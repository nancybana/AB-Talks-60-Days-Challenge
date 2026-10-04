import streamlit as st
import pandas as pd

from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

st.set_page_config(
    page_title="Spam Message Detector",
    page_icon="📩",
    layout="centered"
)

@st.cache_resource
def train_model():
    df = pd.read_csv("spam.csv", encoding="latin-1")

    df = df[["v1", "v2"]]
    df.columns = ["label", "message"]

    df["label"] = df["label"].map({
        "ham": 0,
        "spam": 1
    })

    X_train, X_test, y_train, y_test = train_test_split(
        df["message"],
        df["label"],
        test_size=0.2,
        random_state=42
    )

    vectorizer = TfidfVectorizer(
        stop_words="english",
        lowercase=True
    )

    X_train_vectorized = vectorizer.fit_transform(X_train)
    X_test_vectorized = vectorizer.transform(X_test)

    model = MultinomialNB()
    model.fit(X_train_vectorized, y_train)

    predictions = model.predict(X_test_vectorized)
    accuracy = accuracy_score(y_test, predictions)

    return model, vectorizer, accuracy


model, vectorizer, accuracy = train_model()

st.title("Spam Message Detector")
st.write(
    "Enter a message below and the machine learning model "
    "will predict whether it is **Spam** or **Not Spam**."
)

message = st.text_area(
    "Enter your message:",
    placeholder="Example: Congratulations! You won a free prize..."
)

if st.button("Check Message"):

    if message.strip() == "":
        st.warning("Please enter a message first.")

    else:
        message_vector = vectorizer.transform([message])

        prediction = model.predict(message_vector)[0]

        probability = model.predict_proba(message_vector)[0]

        if prediction == 1:
            st.error("🚨 Spam Message Detected!")
            st.write(
                f"Spam probability: **{probability[1] * 100:.2f}%**"
            )

        else:
            st.success("✅ This message looks safe.")
            st.write(
                f"Safe probability: **{probability[0] * 100:.2f}%**"
            )

st.divider()

st.caption(f"Model Accuracy: {accuracy * 100:.2f}%")
st.caption("Built using Python, Scikit-learn and Streamlit")
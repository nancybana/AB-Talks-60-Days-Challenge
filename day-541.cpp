import pandas as pd
import string
import nltk
from nltk.corpus import stopwords

nltk.download('stopwords')

df = pd.read_csv("spam.csv", encoding='latin-1')

df = df[['v1', 'v2']]
df.columns = ['label', 'message']

print("Dataset Shape:", df.shape)

df['label'] = df['label'].map({'ham': 0, 'spam': 1})

stop_words = set(stopwords.words('english'))

def clean_text(text):
    text = text.lower()
    text = text.translate(str.maketrans('', '', string.punctuation))
    words = text.split()
    words = [word for word in words if word not in stop_words]
    return " ".join(words)

df['clean_message'] = df['message'].apply(clean_text)

print("\nSample Cleaned Data:")
print(df[['message', 'clean_message']].head())

spam_count = df[df['label'] == 1].shape[0]
ham_count = df[df['label'] == 0].shape[0]

print("\nSpam Messages:", spam_count)
print("Non-Spam Messages:", ham_count)

df['length'] = df['message'].apply(len)

print("\nAverage Spam Length:",
      df[df['label'] == 1]['length'].mean())

print("Average Non-Spam Length:",
      df[df['label'] == 0]['length'].mean())
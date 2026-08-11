marks = float(input("Enter your marks: "))

if marks < 0 or marks > 100:
    print("Invalid marks! Please enter marks between 0 and 100.")
elif marks >= 90:
    print("Grade: A")
    print("Status: Passed")
elif marks >= 75:
    print("Grade: B")
    print("Status: Passed")
elif marks >= 50:
    print("Grade: C")
    print("Status: Passed")
else:
    print("Grade: Fail")
    print("Status: Failed")

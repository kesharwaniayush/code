stud = []

# Function to accept the percentage of students
def accept():
    n = int(input("Enter Total Number of Students: "))
    for i in range(n):
        val = float(input(f"Enter Percentage of Student {i+1}: "))
        stud.append(val)

# Function to display the list of student percentages
def display():
    print("\nStudents List (Percentages): ", stud)

# Function for Selection Sort
def selection():
    n = len(stud)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if stud[j] < stud[min_index]:
                min_index = j
        stud[i], stud[min_index] = stud[min_index], stud[i]
    print("\nSorted Percentages using Selection Sort: ")
    print(stud)
    display_top_scores()

# Function for Bubble Sort
def bubble():
    n = len(stud)
    for i in range(n):
        for j in range(0, n-i-1):
            if stud[j] > stud[j+1]:
                stud[j], stud[j+1] = stud[j+1], stud[j]
    print("\nSorted Percentages using Bubble Sort: ")
    print(stud)
    display_top_scores()

# Function to display the top 5 highest scores
def display_top_scores():
    print("\nTop 5 Scores:")
    if len(stud) >= 5:
        top_scores = stud[-5:]  # Get the top 5 scores from the sorted list
    else:
        top_scores = stud  # If there are less than 5 students, display all
    print(top_scores)

# Main menu loop
while(True):
    print("\n1. Enter Student Percentages")
    print("2. Display Student Percentages")
    print("3. Selection Sort")
    print("4. Bubble Sort")
    print("5. Exit")
    ch = int(input("Enter Choice: "))

    if ch == 1:
        accept()
    elif ch == 2:
        display()
    elif ch == 3:
        selection()
    elif ch == 4:
        bubble()
    elif ch == 5:
        print("Exiting the program...")
        break
    else:
        print("Invalid Choice...")
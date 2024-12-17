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

# Function for Insertion Sort
def insertion_sort():
    n = len(stud)
    for i in range(1, n):
        key = stud[i]
        j = i - 1
        while j >= 0 and key < stud[j]:
            stud[j + 1] = stud[j]
            j -= 1
        stud[j + 1] = key
    print("\nSorted Percentages using Insertion Sort: ")
    print(stud)
    display_top_scores()

# Function for Shell Sort
def shell_sort():
    n = len(stud)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = stud[i]
            j = i
            while j >= gap and stud[j - gap] > temp:
                stud[j] = stud[j - gap]
                j -= gap
            stud[j] = temp
        gap //= 2
    print("\nSorted Percentages using Shell Sort: ")
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
    print("3. Insertion Sort")
    print("4. Shell Sort")
    print("5. Exit")
    ch = int(input("Enter Choice: "))

    if ch == 1:
        accept()
    elif ch == 2:
        display()
    elif ch == 3:
        insertion_sort()
    elif ch == 4:
        shell_sort()
    elif ch == 5:
        print("Exiting the program...")
        break
    else:
        print("Invalid Choice...")
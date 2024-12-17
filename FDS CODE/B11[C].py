def binary_search(roll_numbers, target):
    left, right = 0, len(roll_numbers) - 1
    while left <= right:
        mid = (left + right) // 2
        if roll_numbers[mid] == target:
            return True
        elif roll_numbers[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return False


def linear_search(roll_numbers, target):
    for roll_number in roll_numbers:
        if roll_number == target:
            return True
    return False


# Main program
while True:
    print("\n********** Welcome to Student Roll Number Search **********")
    print("1. Linear Search")
    print("2. Binary Search")
    print("3. Exit")
    choice = int(input("Enter your choice: "))
    
    if choice in [1, 2]:
        roll_no = []
        n = int(input("Enter the number of students: "))
        print("Enter roll numbers in sorted order:")
        for i in range(n):
            s = int(input(f"Enter roll number of student {i + 1}: "))
            roll_no.append(s)

        search = int(input("\nEnter the roll number you want to search: "))

        if choice == 1:  # Linear Search
            if linear_search(roll_no, search):
                print(f"\nElement {search} found. The student attended the training program.")
            else:
                print("\nElement not found. The student did not attend the training program.")
        
        elif choice == 2:  # Binary Search
            if binary_search(roll_no, search):
                print(f"\nElement {search} found. The student attended the training program.")
            else:
                print("\nElement not found. The student did not attend the training program.")
    
    elif choice == 3:
        print("Thank You! Exiting the program.")
        break
    else:
        print("Invalid choice! Please select a valid option.")
string = input("Enter a String: ")

# To display index of first appearance of the substring
def first_substring_index():
    substring = input("Enter the substring to find: ")
    index = string.find(substring)
    if index != -1:
        print(f"The substring '{substring}' is found at index {index}.")
    else:
        print(f"The substring '{substring}' is not found in the string.")

# To count the occurrences of each word in a given string
def word_occurrences():
    words = string.split()
    word_count = {}
    
    for word in words:
        word = word.lower()  # Convert to lowercase for case-insensitive counting
        word_count[word] = word_count.get(word, 0) + 1

    print("Occurrences of each word in the string:")
    for word, count in word_count.items():
        print(f"'{word}' occurs {count} time(s).")

# To copy the string
def copy_string():
    copied_string = string
    print("The copied string is:", copied_string)

# Menu
while True:
    print("\n.........MENU.........\n")
    print("1. Display index of first appearance of the substring")
    print("2. Count the occurrences of each word in the string")
    print("3. Copy string")
    print("4. Exit\n")
    
    choice = int(input("Enter your choice (1 to 4): "))
    
    if choice == 1:
        first_substring_index()
    elif choice == 2:
        word_occurrences()
    elif choice == 3:
        copy_string()
    elif choice == 4:
        print("Thank you! Exiting the program.")
        break
    else:
        print("Invalid choice! Please select a valid option.")
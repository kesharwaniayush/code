string = input("Enter a String: ")

# To display the word with the longest length
def display_longest_word():
    words = string.split()
    if not words:
        print("The string is empty.")
        return
    longest_word = max(words, key=len)
    print("The word with the longest length is:", longest_word)

# To determine the frequency of a particular character
def char_frequency():
    char = input("Enter the character you want to find: ")
    count = string.count(char)
    print(f"The letter '{char}' occurs {count} time(s) in the string.")

# To check whether the given string is a palindrome
def check_palindrome():
    cleaned_string = ''.join(filter(str.isalnum, string)).lower()
    if cleaned_string == cleaned_string[::-1]:
        print("The string is a palindrome.")
    else:
        print("The string is not a palindrome.")

# Menu
while True:
    print("\n.........MENU.........\n")
    print("1. Display the word with the longest length")
    print("2. Determine the frequency of a particular character in the string")
    print("3. Check whether the string is a palindrome")
    print("4. Exit\n")
    
    choice = int(input("Enter your choice (1 to 4): "))
    
    if choice == 1:
        display_longest_word()
    elif choice == 2:
        char_frequency()
    elif choice == 3:
        check_palindrome()
    elif choice == 4:
        print("Thank you! Exiting the program.")
        break
    else:
        print("Invalid choice! Please select a valid option.")
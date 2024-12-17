# Collect inputs for students in SE Computer
n = int(input("Enter the number of students in SE Computer: "))
se_students = []
for i in range(n):
    name = input(f"Enter the name of student {i + 1}: ")
    se_students.append(name)

# Collect inputs for students who play cricket
n_cricket = int(input("\nEnter the number of students who play cricket: "))
cricket_players = []
for i in range(n_cricket):
    name = input(f"Enter the name of cricket player {i + 1}: ")
    cricket_players.append(name)

# Collect inputs for students who play badminton
n_badminton = int(input("\nEnter the number of students who play badminton: "))
badminton_players = []
for i in range(n_badminton):
    name = input(f"Enter the name of badminton player {i + 1}: ")
    badminton_players.append(name)

# Collect inputs for students who play football
n_football = int(input("\nEnter the number of students who play football: "))
football_players = []
for i in range(n_football):
    name = input(f"Enter the name of football player {i + 1}: ")
    football_players.append(name)

# Function to compute students who play both cricket and badminton
def cricket_and_badminton(cricket_players, badminton_players):
    return list(set(cricket_players) & set(badminton_players))

# Function to compute students who play cricket and football but not badminton
def cricket_and_football_not_badminton(cricket_players, football_players, badminton_players):
    return list(set(cricket_players) & set(football_players) - set(badminton_players))

# Display the menu and call corresponding functions
while True:
    print("\n\n.........MENU.........")
    print("1. List of students who play both cricket and badminton")
    print("2. Number of students who play cricket and football but not badminton")
    print("3. Exit\n")
    
    choice = int(input("Enter your choice (1 to 3): "))
    
    if choice == 1:
        result = cricket_and_badminton(cricket_players, badminton_players)
        print("Students who play both cricket and badminton:", result)
    elif choice == 2:
        result = cricket_and_football_not_badminton(cricket_players, football_players, badminton_players)
        print("Number of students who play cricket and football but not badminton:", len(result))
        print("Students:", result)
    elif choice == 3:
        print("Exiting the program. Goodbye!")
        break
    else:
        print("Invalid choice. Please try again.")
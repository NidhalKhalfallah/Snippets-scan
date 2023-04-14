import os
#Define a function to create a file that contains private information
def create_private_file(file_path):
    # Check if the file already exists
    if os.path.exists(file_path):
        print(f"File {file_path} already exists")
        return

    # Get private information from the user
    private_info = input("Enter private information: ")

    # Create the file and write the private information to it
    with open(file_path, "w") as f:
        f.write(private_info)

    print(f"File {file_path} created successfully")
import os

# Define the directory containing the video files
directory = r"E:\videos"

# Define the new naming pattern
# You can use a function to generate names based on file attributes if needed
def new_name(index, extension):
    return f"video_{index + 1}{extension}"

# Iterate through all files in the directory
for index, filename in enumerate(os.listdir(directory)):
    # Check if the file is a video file (you can modify this list based on your needs)
    if filename.endswith(('.mp4', '.avi', '.mkv', '.mov')):
        # Full path to the current file
        old_file = os.path.join(directory, filename)
        
        # Get file extension
        extension = os.path.splitext(filename)[1]
        
        # Generate new file name
        new_file = os.path.join(directory, new_name(index, extension))
        
        # Rename the file
        os.rename(old_file, new_file)
        
        print(f"Renamed '{filename}' to '{new_name(index, extension)}'")

print("Renaming complete.")

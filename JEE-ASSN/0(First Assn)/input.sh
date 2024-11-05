read -p "Enter the filename: " FILENAME

if [ ! -f "$FILENAME" ]; then
    echo "File not found: $FILENAME"
    exit 1
fi

# Run the command with the filename
echo "Running command on $FILENAME..."
pdflatex "$FILENAME" 
exit 0

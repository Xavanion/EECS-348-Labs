# Set the base image to use
FROM gcc:latest

# Copy the C program into the container
COPY sales.c .
COPY sales_data.txt .

# Compile the C program
RUN gcc -o sales sales.c

# Set the command to run when the container starts
CMD ["./sales"]

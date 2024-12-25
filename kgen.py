def generate_serial(name):

    serial = sum(ord(char) for char in name)
    
    serial *= len(name)
    
    first_digit = int(str(serial)[0]) 
    serial += first_digit
    
    serial *= 16
    
    return serial

name = input("Enter your name: ")
serial = generate_serial(name)

print(f"Generated serial for {name}: {serial}")

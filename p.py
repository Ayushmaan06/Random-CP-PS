import pandas as pd

# Example data for 6 rows with categorical predictions
data = {
    'ID': [1, 2, 3, 4, 5, 6],  # Replace with your IDs
    'Prediction': ['A', 'B', 'A', 'C', 'B', 'A']  # Replace with your model's categorical predictions
}

# Create a DataFrame
df = pd.DataFrame(data)

# Save DataFrame to CSV
df.to_csv('submission.csv', index=False)

import openai

# Set your OpenAI API key
openai.api_key = "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"

def obfuscate_code(code_snippet):
    prompt = f"Please obfuscate the following Python code:\n\n{code_snippet}"
    
    # Call the OpenAI API with the code snippet as a prompt
    response = openai.Completion.create(
        engine="text-davinci-003",  # Choose the engine suitable for code-related tasks
        prompt=prompt,
        max_tokens=150,  # Adjust as needed
        temperature=0.7,  # Adjust as needed
        n=1
    )

    # Extract the obfuscated code from the API response
    obfuscated_code = response.choices[0].text.strip()
    
    return obfuscated_code

# Example code snippet
input_code = """
def add_numbers(a, b):
    result = a + b
    return result
"""

# Obfuscate the code
obfuscated_code = obfuscate_code(input_code)

# Print the obfuscated code
print("Original Code:\n", input_code)
print("\nObfuscated Code:\n", obfuscated_code)

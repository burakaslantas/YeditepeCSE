input_word = input("Please enter a word: ")
output_list = list()
len_word = len(input_word)
for i in range(0, len_word, 1):
    output_list.append(input_word[i])
print(output_list)
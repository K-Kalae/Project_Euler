def collatz_steps(start_num):
    steps = 0
    while start_num != 1:
        if start_num % 2 == 0:
            start_num //= 2
        else:
            start_num = 3 * start_num + 1
        steps += 1
    return steps

def main():
    list_num_steps = []
    for i in range (1, 1000000):
        list_num_steps.append(collatz_steps(i))
    
    #print(list_num_steps)
    print(list_num_steps.index(max(list_num_steps)))

if __name__ == "__main__":
    main()
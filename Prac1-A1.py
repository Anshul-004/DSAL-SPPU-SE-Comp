def tele_database():
    phone_data = []
    n = int(input("Enter Number of Clients :- "))
    print("Enter Phone Numbers --\n")
    for _ in range(n):
        x = int(input("--> "))
        phone_data.append(x)
    return phone_data


def hash_function_1(key_ele, m_size):
    h1 = key_ele % m_size
    return h1


def hash_function_2(key_ele):
    h2 = 7 - (key_ele % 7)
    return h2


def hashtable(ht):
    print(f"\nHash Value \tKey")
    for ele in range(len(ht)):
        if ht[ele] != -1:
            print(f"\n\t{ele} \t --> \t{ht[ele]}")
        else:
            print(f"\n\t{ele}")

# Main function


print("--- Prepared By - Anshul Singh ---\n")
print("*** DSAL Practical No. 1 (A-1) ***\n")

while (1):
    phone_database = tele_database()
    m = int(input("Enter Hash Table Size :- "))
    hash_table = [-1] * m #creates a list with size m, all elements as -1
    opt = int(input("If collision occurs which collision resolution technique do you want to use?\n\t1. Linear Probing\n\t2. Double Hashing\n\t3. Exit :- "))
    for k in phone_database:
        h_1 = hash_function_1(k, m)
        h_2 = hash_function_2(k)

        if hash_table[h_1] == -1:
            hash_table[h_1] = k
        else:
            if opt == 1:
                while hash_table[h_1] != -1:
                    h_1 += 1
                hash_table[h_1] = k
                hashtable(hash_table)

            elif opt == 2:
                i = 0
                while hash_table[h_1] != -1:
                    i += 1
                    h_1 = (h_1 + (i * h_2)) % m
                hash_table[h_1] = k
                hashtable(hash_table)

            elif opt == 3:
                print("\n*** TERMINATED SUCCESSFULLY ***")
                exit(0)

def t_data():
    teledir = []
    no = int(input("Enter No of Users : "))
    for i in range(no):
        phno = int(input("Enter The Phone Nos : "))
        teledir.append(phno)
    return teledir


def linear_index(key, ht_size):
    return key % ht_size  # returns probable index


def main():
    hashed = []
    print("Telephone Directory !")
    while(1):
        print("Enter Users Data \n")
        teleNo = t_data()  # list me data aagya, which is to be hashed
        n = int(input("Enter hash table size"))
        hashed = [-1] * n

        print("MENU :\n 1. Linear Probing, 2. Quadratic Probing, 3.Exit")
        ch = int(input("Enter Choice"))

        if (ch == 1):
            for i in teleNo:
                l_ind = linear_index(i, n)
                if (hashed[l_ind] == -1):
                    hashed[l_ind] = i
                else:
                    while (hashed[l_ind] != -1):
                        l_ind += 1
                        if (l_ind >= n):
                            l_ind = 0
                    hashed[l_ind] = i
                print(hashed)

        elif (ch == 2):
            for i in teleNo:
                q_ind = linear_index(i, n)
                if (hashed[q_ind] == -1):
                    hashed[q_ind] = i
                else:
                    cnt = 0
                    while (hashed[q_ind] != -1):
                        q_ind = ((q_ind + cnt*cnt) % n) #(h + i^2)%size
                        if (q_ind >= n):
                            q_ind = 0
                        cnt += 1
                    hashed[q_ind] = i
                print(hashed)
        else:
            exit(0)


#function call
main()

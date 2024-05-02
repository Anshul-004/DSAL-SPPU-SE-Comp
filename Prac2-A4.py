def main(): 
    set1 = set() 
    set2 = set() 
    print("PREPARED BY - Anshul Singh\n") 
    print("*** DSAL PRACTICAL NO - 02 (A-04) ***") 
    while(True): 
        print("\n\n==== SET OPERATIONS ====\n") 
        print("\nEnter Your Choice :") 
        choice = int(input("1:Insert \n2:Size \n3:Remove \n4:Contains \n5:Union \n6:Intersection \n7.Subset \n8.Difference \n9.Exit\n")) 
 
        if (choice == 1): 
            n1 = int(input("Enter the number of elements in set 1: \n")) 
            for i in range(n1): 
                data_name = input("Enter the elements in set 1: \n") 
  
                set1.add(data_name) 
            n2 = int(input("\nEnter the number of elements in set 2: \n")) 
            for i in range(n2): 
                data_name = input("Enter the elements in set 2: \n") 
 
                set2.add(data_name) 
 
            print("Set 1 :",set1,'\nSet 2 :',set2) 
 
        elif (choice == 2): 
            print("Size of set1: ", len(set1)) 
            print("Size of set2: ", len(set2)) 
             
        elif (choice == 3): 
            print('Remove element from set 1 and set 2 (1 for set 1 & 2 for set2)\n') 
            inp = int(input()) 
            if inp==1: 
                set1.pop() 
                print(set1) 
            if inp==2: 
                set2.pop() 
                print(set2) 
                 
                 
        elif (choice == 4): 
            ip = input("Enter element you want to check: ") 
            if ip in set1: 
                print("set 1 contains the element ",ip) 
            if ip in set2: 
                print("set 2 contains the element ",ip) 
                 
        elif (choice == 5): 
            print("Union :", set1.union(set2)) 
             
        elif (choice == 6): 
            print("Intersection: ", set1.intersection(set2)) 
             
        elif (choice == 7): 
            if(set1.issubset(set2)): 

                print("Set 1 is Subset of set 2") 
            else: 
                print("Set 1 is Not a Subset of Set 2") 
             
        elif (choice == 8): 
            differ = set2.difference(set1) 
            print(differ) 
             
        else: 
            exit() 
main() 
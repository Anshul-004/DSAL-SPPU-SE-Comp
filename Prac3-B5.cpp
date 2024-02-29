#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

struct node
{
    char label[30];
    int ch_count;
    int sb_count;
    struct node *child[30];
} *root;

class BST
{
public:
    void create_tree();
    void display(node *r1);

    BST()
    {
        root = NULL;
    }
};

void BST::create_tree()
{
    int tbooks, tchapters, i, j, k;
    root = new node();
    cout << "Enter Name of Book : ";
    cin >> root->label;
    cout << "Enter no. of Chapters in Book: ";
    cin >> tchapters;
    root->ch_count = tchapters;

    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "\nEnter Chapter " << i + 1 << " Name: ";
        cin >> root->child[i]->label;
        cout << "Enter no. of Sections in Chapter " << root->child[i]->label << ": ";
        cin >> root->child[i]->ch_count;

        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "\nEnter Section " << j + 1 << " name: ";
            cin >> root->child[i]->child[j]->label;
            cout << "Enter no. of subsections in Section " << root->child[i]->child[j]->label << ": ";
            cin >> root->child[i]->child[j]->sb_count;

            for (k = 0; k < root->child[i]->child[j]->sb_count; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "\nEnter Subsection " << k + 1 << " name: ";
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void BST::display(node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book-----\n";
        cout << "BOOK TITLE: " << r1->label;
        cout << "\n*** CHAPTERS ***" << endl;
        tchapters = r1->ch_count;

        for (i = 0; i < tchapters; i++)
        {
            cout << "\n"
                 << i + 1 << ". " << r1->child[i]->label;

            for (j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n\t" << i + 1 << "." << j + 1 << ". " << r1->child[i]->child[j]->label;

                for (k = 0; k < r1->child[i]->child[j]->sb_count; k++)
                {
                    cout << "\n\t\t" << i + 1 << "." << j + 1 << "." << k + 1 << ". " << r1->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }
}

int main()
{
    int choice;
    BST bst;
    cout << "--- Prepared By : Anshul Singh ---" << endl;
    cout << "--- DSAL Practical No - 3 (B-05) ---" << endl;
    while (1)
    {
        cout << "\n-----------------" << endl;
        cout << "Book Tree Creation" << endl;
        cout << "-----------------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bst.create_tree();
            break;
        case 2:
            bst.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout << "\nWrong Choice!" << endl;
        }
    }
}
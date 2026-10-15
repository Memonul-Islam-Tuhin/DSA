#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    string song;
    Node*next;
    Node(string song)
    {
        this->song = song;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, string song)
{
    Node* newNode = new Node(song);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}


Node* find_song(Node* head, string song)
{
    Node*temp = head;
    while(temp != NULL)
    {
        if(temp->song == song)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}


void play_song(Node* head, Node* &current, string song)
{
    Node*found = find_song(head,song);
    if(found != NULL)
    {
        current = found;
        cout << "playing " << current->song << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}

void move_right(Node* &current)
{
    if(current == NULL || current->next == NULL)
    {
        cout << "Not Found" << endl;
        return;
    }

    current = current->next;
    cout << "playing " << current->song << endl;
}

void move_left(Node* head, Node* &current)
{
    if(current == NULL || current == head)
    {
        cout << "Not Found" << endl;
        return;
    }

    Node*temp = head;
    while(temp->next != current)
    {
        temp = temp->next;
    }

    current = temp;
    cout << "playing " << current->song << endl;
}

int main()
{
    Node*head = NULL;
    Node*tail = NULL;
    Node*current = NULL;

    string song;
    while(cin >> song && song != "stop")
    {
        insert_at_tail(head,tail,song);
    }

    int query;
    cin >> query;
    while(query--)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "play")
        {
            string songName;
            cin >> songName;

            play_song(head,current,songName);
        }
        else if(cmd == "right")
        {
            move_right(current);
        }
        else if(cmd == "left")
        {
            move_left(head,current);
        }
    }

    while(head != NULL)
    {
        Node*temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

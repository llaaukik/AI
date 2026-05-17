#include <iostream> // Input Output operations sathi
using namespace std;

int main()
{
    // User input store karayla string variable

    string user;

    // Heading print karto

    cout<<"----- CUSTOMER CHATBOT -----\n";

    // Viva: Chatbot mhanje kay?
    // Ans: User sobat text-based communication karanara program

    while(true) // Infinite loop
    {
        // Viva: while(true) ka use kela?
        // Ans: Continuous interaction sathi

        cout<<"You: ";

        // User kadun input gheto

        cin>>user;

        // User hello lihila tar greeting message

        if(user=="hello")
        {
            cout<<"Chatbot: Hi! How can I help you?\n";
        }

        // Viva: if condition ka use keli?
        // Ans: User input check karayla

        // Price information

        else if(user=="price")
        {
            cout<<"Chatbot: Product price is 500 rupees.\n";
        }

        // Delivery information

        else if(user=="delivery")
        {
            cout<<"Chatbot: Delivery takes 3 days.\n";
        }

        // Exit condition

        else if(user=="bye")
        {
            cout<<"Chatbot: Thank You!\n";

            // Viva: break ka use kela?
            // Ans: Loop terminate karayla

            break;
        }

        // Invalid input

        else
        {
            cout<<"Chatbot: Sorry, I don't understand.\n";
        }
    }

    return 0;
}

/*
Important Viva:

1) Chatbot kay ahe?
Ans: User sobat conversation karanara software

2) Ha kontya type cha chatbot ahe?
Ans: Rule-based chatbot

3) while loop ka use kela?
Ans: Continuous chatting sathi

4) String ka use keli?
Ans: User text input store karayla

5) Limitation kay ahe?
Ans: Fixed keywords varach kam karto

6) AI concept konta use zala?
Ans: Rule Based AI
*/
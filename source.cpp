#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <thread>
#include <regex>
//#include <ctime>

struct node
{
    struct node *prevNode;
    struct node *leftChild;
    struct node *rightChild;
    int Data = 0;
};

bool isAlive = false;

void makeNode();
void spinner();
void printUsage()
{
    std::cout << "Usage $./main NumberOfNodes" << std::endl;
}

int main(int argc, char *argv[])
{
    int numOfNodes = 0;
    srand(time(NULL));
    try
    {
        std::regex p("[^0-9]");
        if(argc > 2)
        {
            throw std::runtime_error("Too Many Argument");
        }
        else if(argc == 1)
        {
            throw std::runtime_error("Not Enough Argument");
        }
        else if(std::regex_search(argv[1], p))
        {
            throw std::runtime_error("Invalid Argument");
        }
        else
        {
            numOfNodes = atoi(argv[1]); 
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        printUsage();
        exit(-1);
    }

    std::cout << "Nodes being Generated: " << numOfNodes << std::endl;

    struct node* head = NULL;

    for(int i = 0; i < numOfNodes; i++)
    {
    }
    return 0;
}

void makeNode()
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->prevNode = NULL;
}

void spinner()
{
	char spinPos = '|';
	unsigned int positionVal = 0;
	while(!isAlive)
	{
		switch (positionVal)
		{
			case 0:
				spinPos = '/';
				positionVal++;
				break;
			case 1:
				spinPos = '-';
				positionVal++;
				break;
			case 2:
				spinPos = '\\';
				positionVal++;
				break;
			default:
				spinPos = '|';
				positionVal = 0;
				break;
		}
		std::cout << "\rGenerating " << spinPos << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}
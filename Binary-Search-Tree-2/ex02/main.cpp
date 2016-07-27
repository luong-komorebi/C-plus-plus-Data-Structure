#include"dictionary.h"

void main()
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	node * tree = NULL, *tree1 = NULL, *temp;
	wstring word;
	wstring content;
	wcout << "PLease wait!!!" << endl;
	inputfromfile(tree, tree1);
	node* favorite = NULL;
	int choose;
	do
	{
		wcout << "which do you want to do with??( 1:find word; 2:find content, 3: delete word)";
		cin >> choose;
	} while (choose != 1 && choose != 2 && choose != 3);
	switch (choose)
	{
	case 1:
		wcout << "input word: ";
		wcin >> word;
		findbyword(tree, word);
		break;
	case 2:
		wcout << "input content: ";
		wcin.get();
		getline(wcin, content);
		findbycontent(tree1, content);
		break;
	case 3: wcout << "input the word you want to delete: ";
		wcin >> word;
		tree = removeusingright(tree, word);
		outputpreorder(tree);
		wcout << "the word was deleted!!!" << endl;
		break;
	}
	char ans;
	do
	{
		wcout << "Do you want to manage your favorite word???( y/n)";
		cin >> ans;
		if (ans == 'y')
		{
			do
			{
				wcout << "which do you want to do with??( 1:add word; 2:delete word,3: edit content)";
				cin >> choose;
			} while (choose != 1 && choose != 2 && choose != 3);
			switch (choose)
			{
			case 1:
				wcout << "input your favorite word: ";
				wcin >> word;
				temp = findbyword(tree, word);
				if (temp != NULL)
				{
					insertword(favorite, temp->word, temp->content);
				}
				break;
			case 2: wcout << "input the word you want to delete: ";
				wcin >> word;
				favorite = removeusingright(favorite, word);
				wcout << "the word was deleted!!!" << endl;
				break;
			case 3: wcout << "input the word you want to edit: ";
				wcin >> word;
				editcontent(favorite, word);
				wcout << "content was changed!" << endl;
				break;
			}
		}
	} while (ans == 'y');
	wcout << "your favorite word: ";
	outputpreorder(favorite);
	deltree(tree1);
	deltree(favorite);
	deltree(tree);
	tree = NULL;
	tree1 = favorite = NULL;
	system("pause");
}
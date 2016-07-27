#include"Dictionary.h"
void inputfromfile(node *& root, node *&root1)
{
	const std::locale empty_locale = std::locale::empty();
	typedef std::codecvt_utf8<wchar_t> converter_type;
	const converter_type* converter = new converter_type;
	const std::locale utf8_locale = std::locale(empty_locale, converter);
	wifstream in;
	in.open("anhviet.dict");
	wofstream out;
	out.open("word and content.txt");//output word and meaning to file for easily searching
	out.imbue(utf8_locale);
	//in.open("emotional dictionary.txt");
	in.imbue(utf8_locale);
	wstring word, cont, temp;
	in >> word;
	word.erase(word.begin());
	while (!in.eof())
	{
		in >> temp;
		if (in.eof())
			break;
		if (temp[0] != '@')
			cont += L' ' + temp;
		else
		{
			out << word << " : " << cont << endl;
			insertword(root, word, cont);
			insertcontent(root1, word, cont);
			word = temp;
			word.erase(word.begin());
			cont.clear();
		}
	}
	in.close();
}
void deltree(node *&root)
{
	if (root == NULL)
		return;
	deltree(root->left);
	deltree(root->right);
	delete root;
}
void insertword(node * &root, wstring word, wstring content)
{
	if (root == NULL)
	{
		root = new node;
		root->word = word;
		root->content = content;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (root->word>word)
		insertword(root->left, word, content);
	else insertword(root->right, word, content);
}
void insertcontent(node * &root, wstring word, wstring content)
{
	if (root == NULL)
	{
		root = new node;
		root->word = word;
		root->content = content;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (root->content > content)
		insertcontent(root->left, word, content);
	else insertcontent(root->right, word, content);
}
node * findbyword(node * root, wstring word)
{
	if (root == NULL)
	{
		wcout << "Can not find in the dictionary!!" << endl;
		return NULL;
	}
	if (root->word > word)
		return findbyword(root->left, word);
	else if (root->word < word)
		return findbyword(root->right, word);
	else
	{
		wcout << root->word << " : " << root->content << endl;
		return root;
	}
}
void findbycontent(node * root, wstring content)
{
	if (root == NULL)
	{
		wcout << "Can not find in the dictionary!!" << endl;
		return;
	}
	if (root->content > content)
		findbycontent(root->left, content);
	else if (root->content < content)
		findbycontent(root->right, content);
	else
	{
		wcout << root->word << " : " << root->content << endl;
		return;
	}
}
void printtree(node *root)
{
	if (root == NULL)
		return;
	wcout << root->word << " " << root->content << endl;
	printtree(root->left);
	printtree(root->right);
}
node * removeusingright(node *root, wstring key)
{
	if (root == NULL)
		return root;
	if (key>root->word)
		root->right = removeusingright(root->right, key);
	else if (key<root->word)
		root->left = removeusingright(root->left, key);
	else
	{
		if (root->right == NULL)
		{
			node * temp = root->left;
			delete root;
			return temp;
		}
		else if (root->left == NULL)
		{
			node * temp = root->right;
			delete root;
			return temp;
		}
		root->word = findmin(root->right)->word;
		root->content = findmin(root->right)->content;
		root->right = removeusingright(root->right, root->word);
	}
	return root;
}
node * removeusingleft(node * root, wstring key)
{
	if (root == NULL)
		return root;
	if (key>root->word)
		root->right = removeusingleft(root->right, key);
	else if (key<root->word)
		root->left = removeusingleft(root->left, key);
	else
	{
		if (root->right == NULL)
		{
			node * temp = root->left;
			delete root;
			return temp;
		}
		else if (root->left == NULL)
		{
			node * temp = root->right;
			delete root;
			return temp;
		}
		root->word = findmax(root->left)->word;
		root->content = findmin(root->right)->content;
		root->left = removeusingleft(root->left, root->word);
	}
	return root;
}
node * findmin(node * root)
{
	if (root == NULL)
		return root;
	while (root->left != NULL)
		root = root->left;
	return root;
}
node * findmax(node * root)
{
	if (root == NULL)
		return root;
	while (root->right != NULL)
		root = root->right;
	return root;
}
void outputpreorder(node * root)
{
	if (root == NULL)
		return;
	wcout << root->word << " : " << root->content << endl;
	outputpreorder(root->left);
	outputpreorder(root->right);
}
void editcontent(node * root, wstring word)
{
	node * temp = findbyword(root, word);
	cin.get();
	wstring newans;
	wcout << "Input the new content: ";
	getline(wcin, newans);
	temp->content = newans;
}
#include <iostream>
#include <cstdlib>

using namespace std;

enum enQst_Level { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOp_Type { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

         
struct stQuestion {
	short Num1 = 0;
	short Num2 = 0;
	enQst_Level Qst_Level;  
	enOp_Type Op_Type;
	short CorrectAnswer = 0;
	short PlayerAnswer = 0;
	bool AnswerResult = false;
};


struct stQuizz {
	short NumberOfQuestions;
	stQuestion Qst_List[100];
	enQst_Level Qst_Level;
	enOp_Type Op_Type;  
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool isPass = false;
};


short Read_HowManyQuestions() {
	short Qst = 0;

	do
	{
		cout << "How Many Questions : (1 => 100) ";
		cin >> Qst;

	} while (Qst < 1 || Qst > 100);

	return Qst;
}



enQst_Level Read_QuestionsLevel() {    
	short Qst_Level = 1;

	do
	{
		cout << "Enter Questions Level :  [1]:Easy , [2]:Med , [3]:Hard , [4]:Mix  ? ";
		cin >> Qst_Level;

	} while (Qst_Level < 1 || Qst_Level > 4);

	return (enQst_Level)Qst_Level;
}




enOp_Type Read_OpType() {
	short Op = 1;

	do
	{
		cout << "Enter Operation Type :  [1]:Add , [2]:Sub , [3]:Mul , [4]:Div , [5]:Mix  ?";
		cin >> Op;

	} while (Op < 1 || Op > 5);

	return (enOp_Type)Op;
}



string Get_QuestionsLevel_Text(enQst_Level Qst_Level) {
	string arrLevel[4] = { "Easy" , "Med" , "Hard" , "Mix" };

	return arrLevel[Qst_Level - 1];
}



string Get_OpType_Symbol(enOp_Type Op) {

	switch (Op)
	{
	case enOp_Type::Add:
		return "+";

	case enOp_Type::Sub:
		return "-";

	case enOp_Type::Mult:
		return "x";

	case enOp_Type::Div:
		return "/";

	default:
		return "Mix";
	}
}



short Random_Number(short From, short To) {
	return rand() % (To - From + 1) + From;
}


enQst_Level Get_Random_Qst_Level() {
	return (enQst_Level)Random_Number(1, 3); 
}


enOp_Type Get_Random_OpType() {
	return (enOp_Type)Random_Number(1, 4);
}





short SimpleCalculator(short N1, short N2, enOp_Type Op) {

	switch (Op)
	{
	case enOp_Type::Add:
		return N1 + N2;

	case enOp_Type::Sub:
		return N1 - N2;

	case enOp_Type::Mult:
		return N1 * N2;

	case enOp_Type::Div:
		return N1 / N2;

	}
}





stQuestion Generate_Qst(enQst_Level Qst_Level, enOp_Type OpType) {   

	stQuestion Qst;

	if (Qst_Level == enQst_Level::Mix) 
		Qst_Level = Get_Random_Qst_Level(); 

	if (OpType == enOp_Type::MixOp)
		OpType = Get_Random_OpType();

	Qst.Op_Type = OpType; 

	switch (Qst_Level)
	{
	case enQst_Level::Easy:
		Qst.Num1 = Random_Number(1, 10);
		Qst.Num2 = Random_Number(1, 10); 

		Qst.CorrectAnswer = SimpleCalculator(Qst.Num1, Qst.Num2, Qst.Op_Type); 
		Qst.Qst_Level = Qst_Level;          

		return Qst;



	case enQst_Level::Med:
		Qst.Num1 = Random_Number(10, 50);  
		Qst.Num2 = Random_Number(10, 50); 

		Qst.CorrectAnswer = SimpleCalculator(Qst.Num1, Qst.Num2, Qst.Op_Type); 
		Qst.Qst_Level = Qst_Level; 

		return Qst; 



	case enQst_Level::Hard:
		Qst.Num1 = Random_Number(50, 100);  
		Qst.Num2 = Random_Number(50, 100); 

		Qst.CorrectAnswer = SimpleCalculator(Qst.Num1, Qst.Num2, Qst.Op_Type); 
		Qst.Qst_Level = Qst_Level; 

		return Qst; 
	}

	return Qst; 
}




void GenerateQuizzQuestions(stQuizz& Quizz) {

	for (short Qst_Num = 0; Qst_Num < Quizz.NumberOfQuestions; Qst_Num++)  
	{
		Quizz.Qst_List[Qst_Num] = Generate_Qst(Quizz.Qst_Level, Quizz.Op_Type);
	}
}



void Set_ScreenColor(bool Right) {

	if (Right)
		system("color 2F"); //Green
	else
	{
		system("color 4F"); //Red
		cout << "\a";
	}
}




void Print_TheQuestion(stQuizz& Quizz, short Qst_Num) {

	cout << "\n";
	cout << "Question [" << Qst_Num + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
	cout << Quizz.Qst_List[Qst_Num].Num1 << endl;
	cout << Quizz.Qst_List[Qst_Num].Num2 << "  ";
	cout << Get_OpType_Symbol(Quizz.Qst_List[Qst_Num].Op_Type);
	cout << "\n_________________" << endl;

}



short Read_PlayerAnswer() {
	short Answer = 0;

	cin >> Answer;
	return Answer;
}


void Correct_TheQuestionAnswer(stQuizz& Quizz, short Qst_Num) {

	if (Quizz.Qst_List[Qst_Num].PlayerAnswer != Quizz.Qst_List[Qst_Num].CorrectAnswer) {

		Quizz.Qst_List[Qst_Num].AnswerResult = false;
		Quizz.NumberOfWrongAnswers++;

		cout << "Wrong Answer  : -( \n";
		cout << "The Right Answer is : " << Quizz.Qst_List[Qst_Num].CorrectAnswer << endl;
	}
	else {
		Quizz.Qst_List[Qst_Num].AnswerResult = true;
		Quizz.NumberOfRightAnswers++;

		cout << "Right Answer : -) \n";
	}
	cout << endl;

	Set_ScreenColor(Quizz.Qst_List[Qst_Num].AnswerResult);
}



void  Ask_And_Correct_QuestionsListAnswers(stQuizz& Quizz) {

	for (short Qst = 0; Qst < Quizz.NumberOfQuestions; Qst++) 
	{
		Print_TheQuestion(Quizz, Qst);
		Quizz.Qst_List[Qst].PlayerAnswer = Read_PlayerAnswer();
		Correct_TheQuestionAnswer(Quizz, Qst);
	}
	Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}



string Get_FinalResultText(bool Pass) {

	if (Pass)
		return "PASS : -) ";
	else
		return "FAIL : -( ";
}


string Tabs(short NumOfTabs) {

	string t = "";

	for (short i = 1; i < NumOfTabs; i++)
	{
		t += "\t";
	}

	return t;
}


void Print_QuizzResults(stQuizz Quizz) {

	cout << "\n";

	cout << Tabs(3) << "_________________________________________________\n\n";
	cout << Tabs(3) << " Final Results is : " << Get_FinalResultText(Quizz.isPass) << endl;
	cout << Tabs(3) << "_________________________________________________\n\n";

	cout << Tabs(3) << " Number Of Questions       : " << Quizz.NumberOfQuestions << endl;
	cout << Tabs(3) << " Questions Level           : " << Get_QuestionsLevel_Text(Quizz.Qst_Level) << endl;
	cout << Tabs(3) << " Operation Type            : " << Get_OpType_Symbol(Quizz.Op_Type) << endl;
	cout << Tabs(3) << " Number Of Right Questions : " << Quizz.NumberOfRightAnswers << endl;
	cout << Tabs(3) << " Number Of Wrong Questions : " << Quizz.NumberOfWrongAnswers << endl;

	cout << Tabs(3) << "_________________________________________________\n\n";
}



void Play_MathGame() {

	stQuizz Quizz;

	Quizz.NumberOfQuestions = Read_HowManyQuestions();
	Quizz.Qst_Level = Read_QuestionsLevel(); 
	Quizz.Op_Type = Read_OpType();

	GenerateQuizzQuestions(Quizz);
	Ask_And_Correct_QuestionsListAnswers(Quizz);
	Print_QuizzResults(Quizz);
}


void ResetScreen() {
	system("cls");
	system("color f1");
}


void StartGame() {

	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		Play_MathGame();

		cout << endl << "Do U want To Play Again (Y/N) ? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}



int main()
{
	srand((unsigned)time(NULL));

	StartGame();


	system("pause>0");
    return 0;
}
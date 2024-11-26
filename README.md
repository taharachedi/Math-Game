# 🧮 Math Quiz Game in C++ 🎮

> **A fun and interactive console-based quiz game where players solve math problems in multiple levels! 🌟**  

---

## 🌟 Project Overview  
This **C++ project** simulates a Math Quiz game 🧠, where players answer questions with different difficulty levels (Easy, Medium, Hard, and Mixed). Players can choose the number of questions and the type of mathematical operation (Addition, Subtraction, Multiplication, Division, or Mixed). The game checks the answers and provides real-time feedback. Players are given the option to replay the game.  

---

## ✨ Features  
- 🧠 **Multiple Difficulty Levels**: Choose from **Easy**, **Medium**, **Hard**, or **Mixed** levels.  
- ➕ **Various Operations**: Add, subtract, multiply, divide, or a mix of them!  
- 📊 **Real-Time Feedback**: Instant response to answers, with correct and incorrect indications.  
- 🎨 **Dynamic Console Colors**: Green for correct answers, Red for wrong ones.  
- 🏆 **Final Score Summary**: A final report of correct and wrong answers, showing whether the player passed or failed.  
- 🔁 **Replay Option**: Play as many games as you want with a replay prompt.  
- 🤖 **Randomized Questions**: The game generates random numbers for each question, ensuring unique quizzes every time.  

---

## ⚙️ How It Works  

### Core Components  
1. **Player Input**:  
   - The player selects the number of questions, difficulty level, and operation type.  
   - The player answers math questions, which vary based on difficulty and operation type.  

2. **Question Generation**:  
   - **Random Numbers**: Each question consists of two numbers chosen randomly within specific ranges based on the difficulty.  
   - **Operations**: The program can generate addition, subtraction, multiplication, division, or random combinations.  

3. **Answer Checking**:  
   - After the player answers, the program checks the correctness of the answer.  
   - Results are displayed immediately with color feedback (Green for correct, Red for wrong).  

4. **Scoring and Summary**:  
   - The total number of correct and wrong answers are tracked.  
   - The player’s result is displayed as either "PASS" or "FAIL" based on the number of correct answers.  

---

## 🎯 Learning Outcomes

This project helps you explore and implement various C++ programming concepts:

- ✅ **Enums and Structs**: Organizing game elements efficiently.
- ✅ **Functions**: Ensuring modularity and reusability for game logic.
- ✅ **Random Number Generation**: Adding unpredictability to gameplay.
- ✅ **Control Structures**: Utilizing loops and conditionals for decision-making.
- ✅ **Console Formatting**: Using colors and formatted output to enhance interactivity.

---

## 🏁 Ready to Play?

Clone this repository, compile the code, and start challenging the computer! 🚀

---

## ▶️ Sample Output  

Here’s what a typical game output might look like:  

```plaintext
How Many Questions : (1 => 100) 10
Enter Questions Level : [1]:Easy , [2]:Med , [3]:Hard , [4]:Mix ? 1
Enter Operation Type : [1]:Add , [2]:Sub , [3]:Mul , [4]:Div , [5]:Mix ? 1

Question [1/10] 
5
3  +
_________________

Your Answer: 8
Right Answer : -) 

Question [2/10] 
8
4  +
_________________

Your Answer: 15
Wrong Answer  : -( 
The Right Answer is : 12

Final Results is : PASS : -)
_________________________________________________
Number Of Questions       : 10
Questions Level           : Easy
Operation Type            : +
Number Of Right Questions : 8
Number Of Wrong Questions : 2
_________________________________________________

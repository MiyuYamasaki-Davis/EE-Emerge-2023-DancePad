
#pragma once

namespace EEE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	public ref class Board : public System::Windows::Forms::Form
	{
		public:
			Board(void)
			{
				InitializeComponent();
			}

		protected:
			~Board()
			{
				if (components)
				{
					delete components;
				}
			}
		private:
			const int intMax = 101;
			Drawing::Graphics^ g;
			bool nonNumberEntered = false;
			int num;
			int min, min_index;
			int vertices = 25;
			int vertSqr = 5;
			int xPos, yPos;
			int goalXPos, goalYPos;
			int score = 0;
			int countdown = 0;
			int gridPos;
			bool started = false;
			int minChild, prevChild, minParent;
			System::Windows::Forms::Button^ reset;
			System::Windows::Forms::Label^ title;
			System::Windows::Forms::PictureBox^ boardOutline;
			System::Windows::Forms::Button^ start;
			System::Windows::Forms::TextBox^ scoreBox;
			System::IO::Ports::SerialPort^ sp = gcnew SerialPort();;
			array<int, 2>^ connections = gcnew array<int, 2>(2, vertices);
			System::Windows::Forms::Timer^ timer1;
			System::Windows::Forms::TextBox^ scoreTitle;
			System::Windows::Forms::TextBox^ timerTitle;
			System::Windows::Forms::TextBox^ timerBox;
			System::ComponentModel::IContainer^ components;
			System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 30);
			System::Drawing::Image^ picPlayer = Image::FromFile("EEicon.png");
			System::Drawing::Image^ picGoal = Image::FromFile("TIicon.jpg");
			Brush^ blackBrush = gcnew Drawing::SolidBrush(Color::Black);
			Brush^ whiteBrush = gcnew Drawing::SolidBrush(Color::White);
			Brush^ redBrush = gcnew Drawing::SolidBrush(Color::Red);
			Brush^ greenBrush = gcnew Drawing::SolidBrush(Color::Green);
			array<int, 2>^ graph;
			array<int>^ parent;
			array<int>^ key;
			array<bool>^ mstSet;
			array<unsigned char>^ bufferData;
			Random^ randNum = gcnew Random();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->title = (gcnew System::Windows::Forms::Label());
			this->boardOutline = (gcnew System::Windows::Forms::PictureBox());
			this->start = (gcnew System::Windows::Forms::Button());
			this->scoreBox = (gcnew System::Windows::Forms::TextBox());
			this->sp = (gcnew System::IO::Ports::SerialPort(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->scoreTitle = (gcnew System::Windows::Forms::TextBox());
			this->timerTitle = (gcnew System::Windows::Forms::TextBox());
			this->timerBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boardOutline))->BeginInit();
			this->SuspendLayout();
			// 
			// reset
			// 
			this->reset->Location = System::Drawing::Point(13, 13);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(48, 23);
			this->reset->TabIndex = 0;
			this->reset->Text = L"Reset";
			this->reset->UseVisualStyleBackColor = true;
			this->reset->Click += gcnew System::EventHandler(this, &Board::reset_Click);
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->title->Location = System::Drawing::Point(346, 13);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(251, 26);
			this->title->TabIndex = 1;
			this->title->Text = L"EE-Emerge Maze Game";
			// 
			// boardOutline
			// 
			this->boardOutline->Location = System::Drawing::Point(200, 50);
			this->boardOutline->Name = L"boardOutline";
			this->boardOutline->Size = System::Drawing::Size(500, 500);
			this->boardOutline->TabIndex = 2;
			this->boardOutline->TabStop = false;
			// 
			// start
			// 
			this->start->Location = System::Drawing::Point(67, 12);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(48, 23);
			this->start->TabIndex = 3;
			this->start->Text = L"Start";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &Board::start_Click);
			// 
			// scoreBox
			// 
			this->scoreBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scoreBox->Location = System::Drawing::Point(788, 112);
			this->scoreBox->Multiline = true;
			this->scoreBox->Name = L"scoreBox";
			this->scoreBox->Size = System::Drawing::Size(27, 47);
			this->scoreBox->TabIndex = 4;
			this->scoreBox->Text = L"0";
			// 
			// sp
			// 
			this->sp->PortName = L"COM3";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Board::timer1_Tick);
			// 
			// scoreTitle
			// 
			this->scoreTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scoreTitle->Location = System::Drawing::Point(751, 62);
			this->scoreTitle->Name = L"scoreTitle";
			this->scoreTitle->Size = System::Drawing::Size(91, 44);
			this->scoreTitle->TabIndex = 6;
			this->scoreTitle->Text = L"Score";
			// 
			// timerTitle
			// 
			this->timerTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timerTitle->Location = System::Drawing::Point(751, 222);
			this->timerTitle->Name = L"timerTitle";
			this->timerTitle->Size = System::Drawing::Size(91, 44);
			this->timerTitle->TabIndex = 7;
			this->timerTitle->Text = L"Timer";
			// 
			// timerBox
			// 
			this->timerBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timerBox->Location = System::Drawing::Point(776, 272);
			this->timerBox->Name = L"timerBox";
			this->timerBox->Size = System::Drawing::Size(48, 49);
			this->timerBox->TabIndex = 8;
			this->timerBox->Text = L"30";
			// 
			// Board
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 577);
			this->Controls->Add(this->timerBox);
			this->Controls->Add(this->timerTitle);
			this->Controls->Add(this->scoreTitle);
			this->Controls->Add(this->scoreBox);
			this->Controls->Add(this->start);
			this->Controls->Add(this->boardOutline);
			this->Controls->Add(this->title);
			this->Controls->Add(this->reset);
			this->Name = L"Board";
			this->Text = L"Maze Game";
			this->Load += gcnew System::EventHandler(this, &Board::Board_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boardOutline))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void Board_Load(System::Object^ sender, System::EventArgs^ e)
			//Creating Drawing object and establishing initial conditions and serial port
			//Inputs: this object and event handler
			//Outputs: none
		{ 
			g = boardOutline->CreateGraphics();
			sp->ReadTimeout = 10;
			sp->Open();
			score = 0;
		}
		private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e)
			//Resets Drawing object and variables
			//Inputs: this object and event handler
			//Outputs: none
		{ 
			g->Clear(Color::White);
			timer1->Enabled = false;
			scoreBox->Text = "0";
			score = 0;
			timerBox->Text = "30";
			started = false;
		}
		private: System::Void start_Click(System::Object^ sender, System::EventArgs^ e)
			//Starts game
			//Inputs: this object and event handler
			//Outputs: none
		{ 
			//Resets countdown and start variable and timer if fresh game
			if (score == 0 && !started) {
				countdown = 330;
				started = true;
			}
			timer1->Enabled = true;
			
			//Draws initial squares
			for (int i = 0; i < 500; i += 100)
			{
				for (int j = 0; j < 500; j += 100)
				{
					g->FillRectangle(blackBrush, i, j, 100, 100);
					g->FillRectangle(whiteBrush, i + 5, j + 5, 90, 90);
				}
			}

			//Initializes and zeros a new array for connections
			graph = gcnew array<int, 2>(vertices, vertices);
			for (int i = 0; i < vertices; i++)
			{
				for (int j = 0; j < vertices; j++)
				{
					graph[i, j] = 0;
				}
			}

			//Determines randomized weights for every node and connected neighbors
			for (int i = 0; i < vertices; i++)
			{
				if (i < 5) //If node is within the top row
				{
					//Bottom neighbor
					num = randNum->Next(0, 100);
					graph[i,i + 5] = num;
					graph[i + 5,i] = num;
					if (i < 4) //If not rightmost node
					{
						//Right neighbor
						num = randNum->Next(0, 100);
						graph[i,i + 1] = num;
						graph[i + 1,i] = num;
					}
					if (i > 0) //If not leftmost node
					{
						//Left neighbor
						num = randNum->Next(0, 100);
						graph[i,i - 1] = num;
						graph[i - 1,i] = num;
					}
				}
				else if (i > 19) //If node is within the bottom row
				{
					//Top neighbor
					num = randNum->Next(0, 100);
					graph[i,i - 5] = num;
					graph[i - 5,i] = num;
					if (i < 24)
					{
						//Right neighbor
						num = randNum->Next(0, 100);
						graph[i,i + 1] = num;
						graph[i + 1,i] = num;
					}
					if (i > 20)
					{
						//Left neighbor
						num = randNum->Next(0, 100);
						graph[i,i - 1] = num;
						graph[i - 1,i] = num;
					}
				}
				else //If located within middle 3 rows
				{
					if (i % 5 == 0) //If leftmost node
					{
						//Right neighbor
						num = randNum->Next(0, 100);
						graph[i,i + 1] = num;
						graph[i + 1,i] = num;
					}
					else if ((i - 4) % 5 == 0) //If rightmost node
					{
						//Left neighbor
						num = randNum->Next(0, 100);
						graph[i,i - 1] = num;
						graph[i - 1,i] = num;
					}
					else //If in middle 3 nodes
					{
						//Right neighbor
						num = randNum->Next(0, 100);
						graph[i,i + 1] = num;
						graph[i + 1,i] = num;
						//Left neighbor
						num = randNum->Next(0, 100);
						graph[i,i - 1] = num;
						graph[i - 1,i] = num;
					}
					//Bottom neighbor
					num = randNum->Next(0, 100);
					graph[i,i + 5] = num;
					graph[i + 5,i] = num;
					//Top neighbor
					num = randNum->Next(0, 100);
					graph[i,i - 5] = num;
					graph[i - 5,i] = num;
				}
			}
			//Run MST algorithm with given weights array
			this->primMST(graph);
			
			//Establish and draw start point and end point
			num = randNum->Next(0, 4);
			switch (num)
			{
				case 0: //Start in top left
					xPos = 25;
					yPos = 25;
					goalXPos = 425;
					goalYPos = 425;
					break;
				case 1: //Start in top right
					xPos = 425;
					yPos = 25;
					goalXPos = 25;
					goalYPos = 425;
					break;
				case 2: //Start in bottom left
					xPos = 25;
					yPos = 425;
					goalXPos = 425;
					goalYPos = 25;
					break;
				case 3: //Start in bottom right
					xPos = 425;
					yPos = 425;
					goalXPos = 25;
					goalYPos = 25;
					break;
			}
			g->DrawImage(picPlayer, xPos, yPos, 50, 50);
			g->DrawImage(picGoal, goalXPos, goalYPos, 50, 50);
		}

		private: int minKeyEx(int minChild, array<int>^ key, array<bool>^ mstSet)
			//Determine the node with the lowest weight among the MST
			//Inputs: minChild (int*), key (int[]), mstSet (bool[])
			//Outputs: minChild (int*), key (int[]), mstSet (bool[])
		{
			//Default overflow value
			min = intMax;
			min_index = intMax;

			//Check if node is in MST and if it has a smaller value
			for (int i = 0; i < vertices; i++)
				if (key[i] != 0 && key[i] < min && mstSet[i] == false)
					min = key[i], minChild = i;

			return minChild;
		}

		private: System::Void primMST(array<int, 2>^ graph)
			//Runs the MST algorithm
			//Inputs: graph (int[])
			//Outputs: connections (int[][])
		{
			//Initialize arrays and variables
			parent = gcnew array<int>(vertices);
			key = gcnew array<int>(vertices);
			mstSet = gcnew array<bool>(vertices);
			prevChild = intMax;

			//Set arrays to default values
			for (int i = 0; i < vertices; i++)
			{
				parent[i] = intMax;
				key[i] = intMax;
				mstSet[i] = false;
			}

			//Establish first node into MST
			key[0] = 0;
			parent[0] = -1;
			mstSet[0] = true;

			//Guaranteed loop to cover all vertices
			for (int i = 0; i < vertices-1; i++) {
				//Set child and parent to null
				minChild = intMax;
				minParent = intMax;

				for (int j = 0; j < vertices; j++) //Loop to establish current parent-child pair
				{
					if (mstSet[j] == true) //If node is in the MST
					{
						for (int k = 0; k < vertices; k++) //Loop to populate key array with neighboring values for node
						{
							key[k] = graph[k, j];
						}

						//Save location of minChild to compare against
						prevChild = minChild;

						//Run minimum weight function
						minChild = this->minKeyEx(minChild, key, mstSet);

						if (minChild != prevChild) //If function found a child node on first run, or found a lower weight neighbor
						{
							minParent = j;
						}
					}
				}

				//System printout
				System::Diagnostics::Debug::WriteLine("Path for " + minParent + " - " + minChild);

				//Establish connection for wall checking later in program
				connections[0,i] = minParent;
				connections[1,i] = minChild;

				//Add child to MST
				mstSet[minChild] = true;

				//Remove wall associated with connection
				if (minChild - minParent == 5)
					g->FillRectangle(whiteBrush, (100 * (minParent % 5)) + 20, (100 * (minParent / 5)) + 95, 60, 10);
				else if (minChild - minParent == -5)
					g->FillRectangle(whiteBrush, (100 * (minParent % 5)) + 20, (100 * (minParent / 5)) - 5, 60, 10);
				if (minChild - minParent == 1)
					g->FillRectangle(whiteBrush, (100 * (minParent % 5)) + 95, (100 * (minParent / 5)) + 20, 10, 60);
				else if (minChild - minParent == -1)
					g->FillRectangle(whiteBrush, (100 * (minParent % 5)) - 5, (100 * (minParent / 5)) + 20, 10, 60);
			}
		}

		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
			//Repeated timer that fires every 100 ms to detect inputs from serial port
			//Inputs: this object and event handler
			//Outputs: none
		{
			//Initialize bufferData array
			bufferData = gcnew array<unsigned char>(10);

			//Reduce countdown timer
			countdown--;
			timerBox->Text = "" + (countdown / 10);

			//Countdown to start
			if (countdown == 330)
			{

				g->DrawString("3", f, blackBrush, 235, 235);
				g->Clear(Color::White);
			}
			else if (countdown == 320)
			{

				g->DrawString("2", f, blackBrush, 235, 235);
				g->Clear(Color::White);
			}
			else if (countdown == 310)
			{

				g->DrawString("1", f, blackBrush, 235, 235);
				g->Clear(Color::White);
			}

			//As long as game is running still
			if (countdown != 0) 
			{
				//Read in serial port data from Arduino
				try 
				{
					sp->Read(bufferData, 0, 1);
				}
				catch (System::TimeoutException^ e) { ; }

				if (bufferData[0] == 82 || bufferData[0] == 85 || bufferData[0] == 68 || bufferData[0] == 76) //If serial port input is one of the directional characters: R, L, D, U
				{
					//Set node position based on current player position
					gridPos = ((xPos - 25) / 100) + (((yPos - 25) / 100) * 5);

					if (bufferData[0] == 68) //If bufferData == D
					{
						if (yPos < 400)
						{
							//Determine if requested movement goes through a wall
							for (int i = 0; i < vertices; i++)
							{
								if ((connections[0, i] == gridPos && connections[1, i] == gridPos + 5) || (connections[0, i] == gridPos + 5 && connections[1, i] == gridPos)) {
									g->FillEllipse(whiteBrush, xPos, yPos, 50, 50);
									yPos += 100;
									g->DrawImage(picPlayer, xPos, yPos, 50, 50);
								}
							}
						}
					}
					else if (bufferData[0] == 85) //If bufferData == U
					{
						if (yPos > 100)
						{
							//Determine if requested movement goes through a wall
							for (int i = 0; i < vertices; i++)
							{
								if ((connections[0, i] == gridPos && connections[1, i] == gridPos - 5) || (connections[0, i] == gridPos - 5 && connections[1, i] == gridPos)) {
									g->FillEllipse(whiteBrush, xPos, yPos, 50, 50);
									yPos -= 100;
									g->DrawImage(picPlayer, xPos, yPos, 50, 50);
								}
							}
						}
					}
					else if (bufferData[0] == 76) //If bufferData == L
					{
						if (xPos > 100)
						{
							//Determine if requested movement goes through a wall
							for (int i = 0; i < vertices; i++)
							{
								if ((connections[0, i] == gridPos && connections[1, i] == gridPos - 1) || (connections[0, i] == gridPos - 1 && connections[1, i] == gridPos)) {
									g->FillEllipse(whiteBrush, xPos, yPos, 50, 50);
									xPos -= 100;
									g->DrawImage(picPlayer, xPos, yPos, 50, 50);
								}
							}
						}
					}
					else if (bufferData[0] == 82) //If bufferData == R
					{
						if (xPos < 400)
						{
							//Determine if requested movement goes through a wall
							for (int i = 0; i < vertices; i++)
							{
								if ((connections[0, i] == gridPos && connections[1, i] == gridPos + 1) || (connections[0, i] == gridPos + 1 && connections[1, i] == gridPos)) {
									g->FillEllipse(whiteBrush, xPos, yPos, 50, 50);
									xPos += 100;
									g->DrawImage(picPlayer, xPos, yPos, 50, 50);
								}
							}
						}
					}
				}
			}

			//If countdown == 0
			else {
				g->Clear(Color::White);
				System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 24);
				g->DrawString("Game Over", f, blackBrush, 190, 190);
				timer1->Enabled = false;
				started = false;
			}

			//If player reaches goal
			if (xPos == goalXPos && yPos == goalYPos)
			{
				g->Clear(Color::White);
				score++;
				this->scoreBox->Text = "" + score;
				countdown += 100;

				//Randomizes maze again
				start_Click(sender, e);
			}
		}
	};
}

#pragma once

namespace EEE {

		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::IO::Ports;

#define intMax 101

		/// <summary>
		/// Summary for Board
		/// </summary>
	public ref class Board : public System::Windows::Forms::Form
		{
		public:
			Board(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~Board()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^ reset;
		private: System::Windows::Forms::Label^ title;
		private: System::Windows::Forms::PictureBox^ boardOutline;
		private: System::Windows::Forms::Button^ start;
		private: System::Windows::Forms::TextBox^ scoreBox;


		private: int xPos;
		protected: int vertices = 25;
		private: int vertSqr = 5;
		private: int yPos;
		private: int goalXPos;
		private: int goalYPos;
		private: int score = 0;
		private: System::IO::Ports::SerialPort^ sp;
		private: array<int, 2>^ connections = gcnew array<int, 2>(2, vertices);
		private: int countdown = 0;
		private: bool started = false;

		private: String^ readIn = "N";
		private: bool read;

		private: System::Windows::Forms::Timer^ timer1;
		private: System::Windows::Forms::TextBox^ scoreTitle;
		private: System::Windows::Forms::TextBox^ timerTitle;
		private: System::Windows::Forms::TextBox^ timerBox;
		private: System::Windows::Forms::Timer^ timer2;
		private: System::ComponentModel::IContainer^ components;

		protected:

		protected:

		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>


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
				this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
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
				this->title->Location = System::Drawing::Point(310, 13);
				this->title->Name = L"title";
				this->title->Size = System::Drawing::Size(277, 26);
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
				this->Text = L"Memory Game";
				this->Load += gcnew System::EventHandler(this, &Board::Board_Load);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boardOutline))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
			Drawing::Graphics^ g;
		private: bool nonNumberEntered = false;
		private: System::Void Board_Load(System::Object^ sender, System::EventArgs^ e) {
			g = boardOutline->CreateGraphics();
			sp = gcnew SerialPort();
			sp->ReadTimeout = 10;
			sp->PortName = "COM3";
			sp->Open();
			score = 0;
			vertSqr = 5;
			vertices = 25;
		}
		private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e) {
			g->Clear(Color::White);
			timer1->Enabled = false;
			scoreBox->Text = "0";
			score = 0;
			timerBox->Text = "30";
			started = false;
		}
		private: System::Void start_Click(System::Object^ sender, System::EventArgs^ e) {
			if (score == 0 && !started) {
				countdown = 300;
				started = true;
			}
			timer1->Enabled = true;
			Pen^ blackPen = gcnew Pen(Color::Black);
			Brush^ blackBrush = gcnew Drawing::SolidBrush(Color::Black);
			Brush^ whiteBrush = gcnew Drawing::SolidBrush(Color::White);
			Brush^ redBrush = gcnew Drawing::SolidBrush(Color::Red);
			Brush^ greenBrush = gcnew Drawing::SolidBrush(Color::Green);
			for (int i = 0; i < 500; i += 100)
				for (int j = 0; j < 500; j += 100) {
					g->FillRectangle(blackBrush, i, j, 100, 100);
					g->FillRectangle(whiteBrush, i + 5, j + 5, 90, 90);
				}
			array<int, 2>^ graph = gcnew array<int, 2>(vertices,vertices);
			Random^ randNum = gcnew Random();
			int num;
			for (int i = 0; i < vertices; i++)
				for (int j = 0; j < vertices; j++)
					graph[i,j] = 0;
			for (int i = 0; i < vertices; i++) {
				if (i < 5) {
					num = randNum->Next(0, 100);
					graph[i,i + 5] = num;
					graph[i + 5,i] = num;
					if (i < 4) {
						num = randNum->Next(0, 100);
						graph[i,i + 1] = num;
						graph[i + 1,i] = num;
					}
					if (i > 0) {
						num = randNum->Next(0, 100);
						graph[i,i - 1] = num;
						graph[i - 1,i] = num;
					}
				}
				else if (i > 19) {
					num = randNum->Next(0, 100);
					graph[i,i - 5] = num;
					graph[i - 5,i] = num;
					if (i < 24) {
						num = randNum->Next(0, 100);
						graph[i,i + 1] = num;
						graph[i + 1,i] = num;
					}
					if (i > 20) {
						num = randNum->Next(0, 100);
						graph[i,i - 1] = num;
						graph[i - 1,i] = num;
					}
				}
				else {
					if (i % 5 == 0) {
						num = randNum->Next(0, 100);
						graph[i,i + 1] = num;
						graph[i + 1,i] = num;
					}
					else if ((i - 4) % 5 == 0) {
						num = randNum->Next(0, 100);
						graph[i,i - 1] = num;
						graph[i - 1,i] = num;
					}
					else {
						{
							num = randNum->Next(0, 100);
							graph[i,i + 1] = num;
							graph[i + 1,i] = num;
							num = randNum->Next(0, 100);
							graph[i,i - 1] = num;
							graph[i - 1,i] = num;
						}
					}
					num = randNum->Next(0, 100);
					graph[i,i + 5] = num;
					graph[i + 5,i] = num;
					num = randNum->Next(0, 100);
					graph[i,i - 5] = num;
					graph[i - 5,i] = num;
				}
			}
			this->primMST(graph);
			
			num = randNum->Next(0, 25);
			while (num >= 6 && num <= 8 || num >= 11 && num <= 13 || num >= 16 && num <= 18)
				num = randNum->Next(0, 25);
			xPos = (100 * (num % 5)) + 25;
			yPos = (100 * (num / 5)) + 25;
			g->FillEllipse(redBrush, xPos, yPos, 50, 50);

			do {
				num = randNum->Next(0, 25);
				while (num >= 6 && num <= 8 || num >= 11 && num <= 13 || num >= 16 && num <= 18)
					num = randNum->Next(0, 25);
				goalXPos = (100 * (num % 5)) + 30;
				goalYPos = (100 * (num / 5)) + 30;
			} while (xPos == goalXPos - 5 && yPos == goalYPos - 5);
			g->FillRectangle(greenBrush, goalXPos, goalYPos, 40, 40);
		}
		private: System::Int16 minKey(int key[], bool mstSet[]) {
			int min = intMax, min_index = intMax;
			for (int i = 0; i < vertices; i++)
				if (mstSet[i] == false && key[i] < min)
					min = key[i], min_index = i;
			return min_index;
		}
		private: System::Void minKeyEx(int* minChild, array<int>^ key, array<bool>^ mstSet) {
			int min = intMax, min_index = intMax;
			for (int i = 0; i < vertices; i++)
				if (key[i] != 0 && key[i] < min && mstSet[i] == false)
					min = key[i], * minChild = i;
		}
		private: System::Void primMST(array<int, 2>^ graph) {
			Brush^ whiteBrush = gcnew Drawing::SolidBrush(Color::White);
			Brush^ blueBrush = gcnew Drawing::SolidBrush(Color::Blue);
			array<int>^ parent = gcnew array<int>(vertices);
			array<int>^ key = gcnew array<int>(vertices);
			array<bool>^ mstSet = gcnew array<bool>(vertices);
			int minChild = intMax;
			int minParent = intMax;
			int prevChild = intMax;
			int x = 0;
			for (int i = 0; i < vertices; i++)
				parent[i] = intMax, key[i] = intMax, mstSet[i] = false;
			key[0] = 0;
			parent[0] = -1;
			mstSet[0] = true;
			for (int i = 0; i < vertices-1; i++) {
				minChild = intMax;
				minParent = intMax;
				for (int j = 0; j < vertices; j++) {
					if (mstSet[j] == true) {
						for (int num = 0; num < vertices; num++)
							key[num] = graph[num, j];
						prevChild = minChild;
						this->minKeyEx(&minChild, key, mstSet);
						if (minChild != prevChild)
							minParent = j;
					}
				}
				System::Diagnostics::Debug::WriteLine("Path for " + minParent + " - " + minChild);
				connections[0,x] = minParent;
				connections[1,x] = minChild;
				if (x < vertices) { x++; }
				mstSet[minChild] = true;
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
		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			array<unsigned char>^ bufferData = gcnew array<unsigned char>(10);
			Brush^ redBrush = gcnew Drawing::SolidBrush(Color::Red);
			Brush^ whiteBrush = gcnew Drawing::SolidBrush(Color::White);
			Brush^ blackBrush = gcnew Drawing::SolidBrush(Color::Black);
			countdown--;
			timerBox->Text = "" + (countdown / 10);
			if (countdown != 0) {
				try {
					sp->Read(bufferData, 0, 1);
				}
				catch (System::TimeoutException^ e) { ; }
				if (bufferData[0] == 82 || bufferData[0] == 85 || bufferData[0] == 68 || bufferData[0] == 76) {
					int gridPos = ((xPos - 25) / 100) + (((yPos - 25) / 100) * 5);

					if (bufferData[0] == 68) {
						if (yPos < 400) {
							for (int i = 0; i < vertices; i++)
								if ((connections[0, i] == gridPos && connections[1, i] == gridPos + 5) || (connections[0, i] == gridPos + 5 && connections[1, i] == gridPos)) {
									g->FillEllipse(whiteBrush, xPos, yPos, 50, 50);
									yPos += 100;
									g->FillEllipse(redBrush, xPos, yPos, 50, 50);
								}
						}
					}
					else if (bufferData[0] == 85) {
						if (yPos > 100) {
							for (int i = 0; i < vertices; i++)
								if ((connections[0, i] == gridPos && connections[1, i] == gridPos - 5) || (connections[0, i] == gridPos - 5 && connections[1, i] == gridPos)) {
									g->FillEllipse(whiteBrush, xPos, yPos, 50, 50);
									yPos -= 100;
									g->FillEllipse(redBrush, xPos, yPos, 50, 50);
								}
						}
					}
					else if (bufferData[0] == 76) {
						if (xPos > 100) {
							for (int i = 0; i < vertices; i++)
								if ((connections[0, i] == gridPos && connections[1, i] == gridPos - 1) || (connections[0, i] == gridPos - 1 && connections[1, i] == gridPos)) {
									g->FillEllipse(whiteBrush, xPos, yPos, 50, 50);
									xPos -= 100;
									g->FillEllipse(redBrush, xPos, yPos, 50, 50);
								}
						}
					}
					else if (bufferData[0] == 82) {
						if (xPos < 400) {
							for (int i = 0; i < vertices; i++)
								if ((connections[0, i] == gridPos && connections[1, i] == gridPos + 1) || (connections[0, i] == gridPos + 1 && connections[1, i] == gridPos)) {
									g->FillEllipse(whiteBrush, xPos, yPos, 50, 50);
									xPos += 100;
									g->FillEllipse(redBrush, xPos, yPos, 50, 50);
								}
						}
					}
				}
			}
			else {
				g->Clear(Color::White);
				System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 24);
				g->DrawString("Game Over", f, blackBrush, 200, 200);
				timer1->Enabled = false;
				started = false;
			}
			if (xPos == goalXPos - 5 && yPos == goalYPos - 5) {
				g->Clear(Color::White);
				score++;
				this->scoreBox->Text = "" + score;
				start_Click(sender, e);
			}
		}
	};
}
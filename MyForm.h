#pragma once

#include "Fish.h"
#include <cliext/vector>
#include "Food.h"
#include <iterator>
#include "Caviar.h"
#include "Aquarium.h"
#include "HFish.h"

namespace FishProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Collections::Generic;
	using namespace System::Drawing::Drawing2D;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>



	public ref class MyForm : public System::Windows::Forms::Form
	{
		cliext::vector<Fish^>^ fishs = gcnew cliext::vector<Fish^>();
		cliext::vector<Food^>^ foods = gcnew cliext::vector<Food^>();
		cliext::vector<HFish^>^ hfishs = gcnew cliext::vector<HFish^>();
		cliext::vector<Caviar^>^ caviars = gcnew cliext::vector<Caviar^>();
		Aquarium^ aquarium = gcnew Aquarium();
	private: System::Windows::Forms::Timer^ timerUpdate;
	private: System::Windows::Forms::Timer^ moveFIshTimer;
	private: int fishGenerationCount = 0;
	private: int hfishGenerationCount = 0;
	private: System::Windows::Forms::Button^ foodButton;
	private: System::Windows::Forms::Timer^ foodColdown;
	private: bool isStarted = false, foodColdownFlag = false;
	private: System::Windows::Forms::Button^ clearButton;
	private: System::Windows::Forms::TextBox^ trashLvlTextBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ hfishCountBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ remontButton;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox;
	protected:
	private: System::Windows::Forms::Button^ closeButton;
	private: System::Windows::Forms::Button^ generationButton;
	private: System::Windows::Forms::PictureBox^ drawingBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ fishCountBox;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->trashLvlTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->remontButton = (gcnew System::Windows::Forms::Button());
			this->foodButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->fishCountBox = (gcnew System::Windows::Forms::TextBox());
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->generationButton = (gcnew System::Windows::Forms::Button());
			this->drawingBox = (gcnew System::Windows::Forms::PictureBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->timerUpdate = (gcnew System::Windows::Forms::Timer(this->components));
			this->moveFIshTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->foodColdown = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->hfishCountBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->drawingBox))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox
			// 
			this->groupBox->Controls->Add(this->hfishCountBox);
			this->groupBox->Controls->Add(this->label3);
			this->groupBox->Controls->Add(this->trashLvlTextBox);
			this->groupBox->Controls->Add(this->label2);
			this->groupBox->Controls->Add(this->clearButton);
			this->groupBox->Controls->Add(this->remontButton);
			this->groupBox->Controls->Add(this->foodButton);
			this->groupBox->Controls->Add(this->label1);
			this->groupBox->Controls->Add(this->fishCountBox);
			this->groupBox->Controls->Add(this->closeButton);
			this->groupBox->Controls->Add(this->generationButton);
			this->groupBox->Location = System::Drawing::Point(12, 12);
			this->groupBox->Name = L"groupBox";
			this->groupBox->Size = System::Drawing::Size(1358, 126);
			this->groupBox->TabIndex = 0;
			this->groupBox->TabStop = false;
			this->groupBox->Text = L"Панель управления";
			// 
			// trashLvlTextBox
			// 
			this->trashLvlTextBox->Location = System::Drawing::Point(1054, 89);
			this->trashLvlTextBox->Name = L"trashLvlTextBox";
			this->trashLvlTextBox->Size = System::Drawing::Size(123, 22);
			this->trashLvlTextBox->TabIndex = 8;
			this->trashLvlTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(881, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(167, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Текущий уровень грязи:";
			// 
			// clearButton
			// 
			this->clearButton->Location = System::Drawing::Point(723, 21);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(152, 40);
			this->clearButton->TabIndex = 6;
			this->clearButton->Text = L"Чистка";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &MyForm::clearButton_Click);
			// 
			// remontButton
			// 
			this->remontButton->Location = System::Drawing::Point(723, 80);
			this->remontButton->Name = L"remontButton";
			this->remontButton->Size = System::Drawing::Size(152, 40);
			this->remontButton->TabIndex = 5;
			this->remontButton->Text = L"Ремонтировать";
			this->remontButton->UseVisualStyleBackColor = true;
			this->remontButton->Click += gcnew System::EventHandler(this, &MyForm::remontButton_Click);
			// 
			// foodButton
			// 
			this->foodButton->Location = System::Drawing::Point(565, 21);
			this->foodButton->Name = L"foodButton";
			this->foodButton->Size = System::Drawing::Size(152, 40);
			this->foodButton->TabIndex = 4;
			this->foodButton->Text = L"Покормить";
			this->foodButton->UseVisualStyleBackColor = true;
			this->foodButton->Click += gcnew System::EventHandler(this, &MyForm::foodButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Начальное количество рыбок:";
			// 
			// fishCountBox
			// 
			this->fishCountBox->Location = System::Drawing::Point(272, 39);
			this->fishCountBox->Name = L"fishCountBox";
			this->fishCountBox->Size = System::Drawing::Size(287, 22);
			this->fishCountBox->TabIndex = 2;
			this->fishCountBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// closeButton
			// 
			this->closeButton->Location = System::Drawing::Point(1200, 80);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(152, 40);
			this->closeButton->TabIndex = 1;
			this->closeButton->Text = L"Закрыть";
			this->closeButton->UseVisualStyleBackColor = true;
			this->closeButton->Click += gcnew System::EventHandler(this, &MyForm::closeButton_Click);
			// 
			// generationButton
			// 
			this->generationButton->Location = System::Drawing::Point(565, 80);
			this->generationButton->Name = L"generationButton";
			this->generationButton->Size = System::Drawing::Size(152, 40);
			this->generationButton->TabIndex = 0;
			this->generationButton->Text = L"Генерация";
			this->generationButton->UseVisualStyleBackColor = true;
			this->generationButton->Click += gcnew System::EventHandler(this, &MyForm::generationButton_Click);
			// 
			// drawingBox
			// 
			this->drawingBox->BackColor = System::Drawing::Color::Transparent;
			this->drawingBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"drawingBox.BackgroundImage")));
			this->drawingBox->Location = System::Drawing::Point(12, 144);
			this->drawingBox->Name = L"drawingBox";
			this->drawingBox->Size = System::Drawing::Size(1358, 597);
			this->drawingBox->TabIndex = 1;
			this->drawingBox->TabStop = false;
			this->drawingBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::onPaint);
			// 
			// timerUpdate
			// 
			this->timerUpdate->Interval = 25;
			this->timerUpdate->Tick += gcnew System::EventHandler(this, &MyForm::timerUpdate_Tick);
			// 
			// moveFIshTimer
			// 
			this->moveFIshTimer->Interval = 500;
			this->moveFIshTimer->Tick += gcnew System::EventHandler(this, &MyForm::moveFIshTimer_Tick);
			// 
			// foodColdown
			// 
			this->foodColdown->Interval = 1000;
			this->foodColdown->Tick += gcnew System::EventHandler(this, &MyForm::foodColdown_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(38, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 17);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Из них хищных:";
			// 
			// hfishCountBox
			// 
			this->hfishCountBox->Location = System::Drawing::Point(272, 89);
			this->hfishCountBox->Name = L"hfishCountBox";
			this->hfishCountBox->Size = System::Drawing::Size(287, 22);
			this->hfishCountBox->TabIndex = 10;
			this->hfishCountBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1382, 753);
			this->Controls->Add(this->groupBox);
			this->Controls->Add(this->drawingBox);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox->ResumeLayout(false);
			this->groupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->drawingBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void closeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}


		   // ...
		   // ...
		   // ...


	private: System::Void generationButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			fishGenerationCount = Convert::ToInt32(fishCountBox->Text);
			hfishGenerationCount = Convert::ToInt32(hfishCountBox->Text);
			fishCountBox->Text = Convert::ToString(fishGenerationCount);
			hfishCountBox->Text = Convert::ToString(hfishGenerationCount);
			if (fishGenerationCount > 20) {
				MessageBox::Show("Пожалуйста, укажите меньшее количество рыбок", "Предупреждение",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				fishGenerationCount = 0;
				hfishGenerationCount = 0;
				return;
			}
			if (fishGenerationCount < 1) {
				MessageBox::Show("Начальное количество рыбок должно быть больше 0", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				fishGenerationCount = 0;
				hfishGenerationCount = 0;
				return;
			}
			if ((fishGenerationCount < 0) || (hfishGenerationCount < 0)) {
				MessageBox::Show("Количество рыб не может быть отрицательным числом", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				fishGenerationCount = 0;
				hfishGenerationCount = 0;
				return;
			}
			if (fishGenerationCount < hfishGenerationCount) {
				MessageBox::Show("Общее количество рыб не может быть меньше количества хищных рыб", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				fishGenerationCount = 0;
				hfishGenerationCount = 0;
				return;
			}
			//блок всей начальной инициализации
			aquarium = gcnew Aquarium();
			aquarium->ventIsCrush += gcnew AquariumVentHandler(this, &FishProject::MyForm::ventIsCrush);
			aquarium->remontSuccess += gcnew AquariumVentHandler(this, &FishProject::MyForm::remontSuccess);
			drawingBox->Controls->Clear();
			timerUpdate->Start();
			moveFIshTimer->Start();
			foodColdown->Start();
			isStarted = true;
			fishs->clear();
			hfishs->clear();
			foods->clear();
			caviars->clear();
			fishs = gcnew cliext::vector<Fish^>();
			hfishs = gcnew cliext::vector<HFish^>();
			foods = gcnew cliext::vector<Food^>();
			caviars = gcnew cliext::vector<Caviar^>();
			Random^ rand = gcnew Random();
			fishGenerationCount -= hfishGenerationCount;
			for (int i = 0; i < fishGenerationCount; i++) {
				fishs->push_back(gcnew Fish(rand->Next(0, drawingBox->Size.Width - 100),
					rand->Next(0, drawingBox->Size.Height - 100), rand->Next(1, 6), rand->Next(1, 4)));
				fishs[i]->death += gcnew DeleteFishHandler(this, &FishProject::MyForm::Ondeath);
				fishs[i]->createCaviar += gcnew CreateCaviarHandler(this, &FishProject::MyForm::OncreateCaviar);
				fishs[i]->foodEating += gcnew FoodEatingHandler(this, &FishProject::MyForm::OndeleteFood);
			}
			for (int i = 0; i < hfishGenerationCount; i++) {
				hfishs->push_back(gcnew HFish(rand->Next(0, drawingBox->Size.Width - 100),
					rand->Next(0, drawingBox->Size.Height - 100), rand->Next(1, 6)));
				hfishs[i]->death += gcnew DeleteFishHandler(this, &FishProject::MyForm::HOndeath);
				hfishs[i]->createCaviar += gcnew CreateCaviarHandler(this, &FishProject::MyForm::OncreateCaviar);
				hfishs[i]->foodEating += gcnew FoodEatingHandler(this, &FishProject::MyForm::OndeleteFood);
				hfishs[i]->fishEating += gcnew fishEatingHandler(this, &FishProject::MyForm::Ondeath);
				for (int j = 0; j < fishs->size(); j++) {
					fishs[j]->existsFish += gcnew ExistsFishHandler(hfishs[i], &HFish::fishDetectedMethod);
				}
			}
			/// ...
			/// /// ... Тут будет ещё много кода ;( (а может и не очень)
			/// /// ...
		}
		catch (...) { // Ловим некорректный ввод (очевидно что Exception будет кидать конвертер,
			          // поэтому ловим любое исключение через ...
			MessageBox::Show("Неправильный ввод!", "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

private: System::Void onPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	//отрисовка объектов
	Graphics^ g = e->Graphics;
	for (int i = 0; i < fishs->size(); i++) {
		fishs[i]->drawSprite(g);
	}
	for (int i = 0; i < hfishs->size(); i++) {
		hfishs[i]->drawSprite(g);
	}
	for (int i = 0; i < foods->size(); i++) {
		foods[i]->drawSprite(g);
	}
	for (int i = 0; i < caviars->size(); i++) {
		caviars[i]->drawSprite(g);
	}
}
private: void update() { //основной цикл отвещающий за анимацию и основное изменение свойств -> генерация событий
	Random^ rand = gcnew Random();
	if (aquarium->ventIsWork == 1) {
		if (rand->Next(1, 10000) == 5000) { //случайная вероятность поломки компрессора в аквариуме
			aquarium->ventIsWork = 0;
		}
	}
	else {
		if (aquarium->isRemont) {
			aquarium->remontTimer--; //если идёт ремонт уменьшаем счётчик
		}
	}
	for (int i = 0; i < fishs->size(); i++) { //обработка для простых рыб
		if (fishs[i]->foodCd != 0) {
			fishs[i]->foodCd--;
			fishs[i]->moveAnim();
			continue;
		}
		fishs[i]->moveAnim();
		if (aquarium->ventIsWork) { //разный перерасчёт энергии в зависимости от состояния компрессора
			fishs[i]->energy -= (0.3 + (aquarium->currentTrash / 50));
		}
		else {
			fishs[i]->energy -= (0.3 + (10 * aquarium->ventIsWork) + (aquarium->currentTrash / 50));
		}
	}
	for (int i = 0; i < hfishs->size(); i++) { //для хищных рыб
		if (hfishs[i]->foodCd != 0) {
			hfishs[i]->foodCd--;
			hfishs[i]->moveAnim();
			continue;
		}
		hfishs[i]->moveAnim();
		if (aquarium->ventIsWork) { //разный перерасчёт энергии в зависимости от состояния компрессора
			hfishs[i]->energy -= (0.5 + (aquarium->currentTrash / 50));
		}
		else {
			hfishs[i]->energy -= (0.5 + (10 * aquarium->ventIsWork) + (aquarium->currentTrash / 50));
		}
	}
	for (int i = 0; i < foods->size(); i++) {
		foods[i]->moveAnim();
	}
	for (int i = 0; i < caviars->size(); i++) {
		caviars[i]->moveAnim();
	}
	if (aquarium->currentTrash < 100) {
		aquarium->currentTrash += fishs->size() * 0.001; //увеличение общей загрязнённости от текущего кол-ва рыб
	}
	this->trashLvlTextBox->Text = Convert::ToString(Convert::ToInt32(aquarium->currentTrash)) + "%";
	Invalidate();
}
private: System::Void timerUpdate_Tick(System::Object^ sender, System::EventArgs^ e) {
	update();
}
private: System::Void moveFIshTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	// генерация рандомного движения для рыбок
	Random^ rand = gcnew Random();
	for (int i = 0; i < fishs->size(); i++) {
		if (!fishs[i]->doSeeFood) {
			if (rand->Next(0, 11) > 7) {
				fishs[i]->move(rand->Next(0, drawingBox->Size.Width - 50),
					rand->Next(0, drawingBox->Size.Height - 50));
			}
		}
	}
	for (int i = 0; i < hfishs->size(); i++) {
		if (!hfishs[i]->doSeeFood) {
			if (rand->Next(0, 11) > 7) {
				hfishs[i]->move(rand->Next(0, drawingBox->Size.Width - 50),
					rand->Next(0, drawingBox->Size.Height - 50));
			}
		}
	}
}
private: System::Void foodButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isStarted || foodColdownFlag) return; // генерация еды и подписки на события
	Random^ rand = gcnew Random();
	Food^ food = gcnew Food(rand->Next(0, drawingBox->Width), 0);
	food->deleteFood += gcnew DeleteFoodHandler(this, &FishProject::MyForm::OndeleteFood);
	for (int i = 0; i < fishs->size(); i++) {
		food->existsFood += gcnew ExistsFoodHandler(fishs[i], &Fish::foodDetectedMethod);
	}
	for (int i = 0; i < hfishs->size(); i++) {
		food->existsFood += gcnew ExistsFoodHandler(hfishs[i], &HFish::foodDetectedMethod);
	}
	foods->push_back(food);
	foodColdownFlag = true;
}
private: System::Void foodColdown_Tick(System::Object^ sender, System::EventArgs^ e) {
	foodColdownFlag = false;
}
private: double calculateDistance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
private: void ventIsCrush() {
	MessageBox::Show("Компрессор сломался, срочно начните ремонт!", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Warning);
}
private: void remontSuccess() {
	aquarium->ventIsWork = 1;
	aquarium->remontTimer = 150;
	aquarium->isRemont = false;
	MessageBox::Show("Ремонт был успешно завершён!", "Ситуация под контролем", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void remontButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (aquarium->ventIsWork == 1) {
		return;
	}
	else {
		aquarium->isRemont = true;
	}
}
private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isStarted) return;
	aquarium->currentTrash -= 5;
	if (aquarium->currentTrash < 0) {
		aquarium->currentTrash = 0;
	}
}
	   void Ondeath(Object^ sender) { // удаление рыбы по ссылке
		   for (int i = 0; i < fishs->size(); i++) {
			   if (fishs[i] == sender) {
				   delete fishs[i];
				   fishs[i] = nullptr;
				   fishs->erase(fishs->begin() + i);
				   break;
			   }
		   }
	   }
	   void HOndeath(System::Object^ sender) { // удаление хищ. рыбы по ссылке
		   for (int i = 0; i < hfishs->size(); i++) {
			   if (hfishs[i] == sender) {
				   delete hfishs[i];
				   hfishs[i] = nullptr;
				   hfishs->erase(hfishs->begin() + i);
				   break;
			   }
		   }
	   }
	   void OndeleteFood(System::Object^ sender) { // удаление еды по ссылке
		   for (int i = 0; i < foods->size(); i++) {
			   if (foods[i] == sender) {
				   delete foods[i];
				   foods[i] = nullptr;
				   foods->erase(foods->begin() + i);
				   break;
			   }
		   }
	   }
	   void OndeleteCaviar(System::Object^ sender) { // удаление икры по ссылке
		   for (int i = 0; i < caviars->size(); i++) {
			   if (caviars[i] == sender) {
				   delete caviars[i];
				   caviars[i] = nullptr;
				   caviars->erase(caviars->begin() + i);
				   break;
			   }
		   }
	   }
	   void OncreateCaviar(double x, double y, int color, bool hunt) { // создание икры и подписки на события
		   Caviar^ caviar = gcnew Caviar(x, y, color, hunt);
		   caviar->deleteCaviar += gcnew CaviarDeleteHandler(this, &FishProject::MyForm::OndeleteCaviar);
		   caviar->fishBirth += gcnew FishBirthHandler(this, &FishProject::MyForm::OnfishBirth);
		   caviars->push_back(caviar);
	   }
	   void OnfishBirth(double x, double y, int color, bool hunt, Object^ sender) {
		   if (hunt) { // рождение рыбы, в зависимости от гена и подписки на события, и удаление икры
			   HFish^ hfish = gcnew HFish(x, y, 1);
			   hfish->death += gcnew DeleteFishHandler(this, &FishProject::MyForm::HOndeath);
			   hfish->createCaviar += gcnew CreateCaviarHandler(this, &FishProject::MyForm::OncreateCaviar);
			   hfish->foodEating += gcnew FoodEatingHandler(this, &FishProject::MyForm::OndeleteFood);
			   hfish->fishEating += gcnew fishEatingHandler(this, &FishProject::MyForm::Ondeath);
			   for (int i = 0; i < foods->size(); i++) {
				   foods[i]->existsFood += gcnew ExistsFoodHandler(hfish, &HFish::foodDetectedMethod);
			   }
			   for (int i = 0; i < fishs->size(); i++) {
				   fishs[i]->existsFish += gcnew ExistsFishHandler(hfish, &HFish::fishDetectedMethod);
			   }
			   hfishs->push_back(hfish);
		   }
		   else {
			   Fish^ fish = gcnew Fish(x, y, 1, color);
			   fish->death += gcnew DeleteFishHandler(this, &FishProject::MyForm::Ondeath);
			   fish->createCaviar += gcnew CreateCaviarHandler(this, &FishProject::MyForm::OncreateCaviar);
			   fish->foodEating += gcnew FoodEatingHandler(this, &FishProject::MyForm::OndeleteFood);
			   for (int i = 0; i < foods->size(); i++) {
				   foods[i]->existsFood += gcnew ExistsFoodHandler(fish, &Fish::foodDetectedMethod);
			   }
			   for (int i = 0; i < hfishs->size(); i++) {
				   fish->existsFish += gcnew ExistsFishHandler(hfishs[i], &HFish::fishDetectedMethod);
			   }
			   fishs->push_back(fish);
		   }
		   OndeleteCaviar(sender);
	   }
};
}


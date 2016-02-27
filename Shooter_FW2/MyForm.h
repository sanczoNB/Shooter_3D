#define _USE_MATH_DEFINES
#include <math.h>
#include <d3d9.h>
#include "Keyboard_control.h"
#include "Pojemnik_na_bryly.h"
#include "Player_Ship.h"
#include "Szescian.h"
#include "Czworoscian.h"
#include "Walec.h"
#include "Shot.h"
#include "Detect_Intersections.h"
#include "Enemy_Ships.h"
#include "Difficulty_and_level.h"
#include "Digits_on_screen.h"
#include "Letters_on_screen.h"

#pragma once

namespace Shooter_FW2 {

	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::DirectX;
	using namespace Microsoft::DirectX::Direct3D;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			InicjalizujUrzadzenie();
			CreateLight();
			UtworzObiekt();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private: array<CustomVertex::PositionNormalColored>^ linia_X;
	private: array<CustomVertex::PositionNormalColored>^ linia_Y;
	private: array<CustomVertex::PositionNormalColored>^ linia_Z;
	private: array<CustomVertex::PositionNormalColored>^ celownik;
	private: Vector3 view_position;
	private: Vector3 view_focus;
	private: const float perspective_field_of_view=(float)(M_PI/2.4f);
	private: float obrot;
	private: Device^ device;
	private: Light^ light1;
	private: float far_plane = 21.0f;
	private: Vector3 aim;
	private: Keyboard_control^ keyboard1;
	private: Pojemnik_na_bryly Pojemnik;
	private: Pojemnik_na_bryly poj_na_strzaly;
	private: Pojemnik_na_bryly poj_na_strzaly_wroga;
	private: Pojemnik_na_bryly Sign_Game_Over;
	private: Pojemnik_na_bryly Level_sign;
	private: Pojemnik_na_bryly Shot_counter;
	private: Pojemnik_na_bryly Difficulty;
	private: Pojemnik_na_bryly Play_Again;
	private: Player_Ship^ main_ship;
	private: Detect_Intersections detect_intrsc;
	private: Enemy_Ships^ sh;
	private: bool GAME_OVER = true;
	private: array<Vector3>^ intersect_aim;
	private: Difficulty_and_level^ level_and_difficulty;
	private: Letters_on_screen^ difficulty_sign;
	private: Letters_on_screen^ LVL;
	private: INT previous_difficulty;


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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 5;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);

			this->timer2->Enabled = true;
			this->timer2->Interval = 100;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// MyForm
			// 
			
			this->Resize += gcnew System::EventHandler(this, &MyForm::Form1_Resize);
			this->PreviewKeyDown += gcnew PreviewKeyDownEventHandler(this, &MyForm::Form1_KeyDown);
			this->KeyUp += gcnew KeyEventHandler(this, &MyForm::Form1_KeyUp);
			this->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::Form1_KeyPress);
			this->MouseMove += gcnew MouseEventHandler(this, &MyForm::Form1_MouseMove);
			this->MouseClick += gcnew MouseEventHandler(this, &MyForm::Form1_Mouse_LClick);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Cursor = System::Windows::Forms::Cursors::Cross;
			this->Name = L"MyForm";
			this->Text = L"3D_Shooter";
			this->ResumeLayout(false);

			SetStyle(ControlStyles::DoubleBuffer, true);
			SetStyle(ControlStyles::AllPaintingInWmPaint, true);
			SetStyle(ControlStyles::UserPaint, true);
			SetStyle(ControlStyles::SupportsTransparentBackColor, true);
			SetStyle(ControlStyles::Opaque, false);
			SetStyle(ControlStyles::OptimizedDoubleBuffer, true);
			SetStyle(ControlStyles::ResizeRedraw, true);
			FormBorderStyle = Windows::Forms::FormBorderStyle::Sizable;
			Top = 0;
			Left = 0;

			Width = Screen::PrimaryScreen::get()->Bounds.Width;
			Height = Screen::PrimaryScreen::get()->Bounds.Height;
		}

		void Resizing_window(const int& wid, const int& hei){
		
			device->EndScene();
			if (device->DisplayMode.Height != hei)
				device->DisplayMode.Height = hei;
			if (device->DisplayMode.Width != wid)
				device->DisplayMode.Width = wid;
		}

		void InicjalizujUrzadzenie() {
			
			view_position = Vector3(0.0f, 1.8f, -2.0f); //vector3(0.0f,1.8f,-2.0f)
			view_focus = Vector3(0.0f, 1.20f, 1.0f); // Vector3(0.0f, 0.80f, 4.5f);

			PresentParameters^ pp = gcnew PresentParameters();

			pp->SwapEffect = SwapEffect::Flip;
			pp->Windowed = true;

			pp->EnableAutoDepthStencil = true;
			pp->AutoDepthStencilFormat = DepthFormat::D16;
			//pp->Windowed = true;

			device = gcnew Device(0, DeviceType::Hardware, this, CreateFlags::SoftwareVertexProcessing, pp);
			device->DisplayMode.Height = Height;
			device->DisplayMode.Width = Width;
			device->Transform->View = Matrix::LookAtLH(view_position, view_focus, Vector3(0, 1, 0));
			keyboard1 = gcnew Keyboard_control(ClientSize.Height, ClientSize.Width, device, view_position, view_focus, Vector3(0.0f, 1.0f, 0.0f));
			device->Transform->Projection = Matrix::PerspectiveFovLH(perspective_field_of_view, (float)ClientSize.Width / ClientSize.Height, 1.0f, far_plane);
			device->Transform->World = Matrix::Identity;
			device->RenderState->CullMode = Cull::None;
			device->SetRenderState(RenderStates::ZEnable, true);
			
			level_and_difficulty = gcnew Difficulty_and_level();
					
			obrot = 0.0f;
		}

		void CreateLight(){
			light1 = gcnew Light();
			//Material^ material1 = gcnew Material();
			//material1->Ambient::set(Color::White);
			//material1->Emissive::set(Color::Yellow);
			//material1->Diffuse::set(Color::White);
			device->Material.Ambient = (Color::White);
			device->Material.Diffuse = Color::White;
			device->Material.DiffuseColor::set(ColorValue::FromColor(Color::White));
			device->Material.Emissive = Color::Yellow;
			device->Material.Specular = Color::White;
			device->Material.SpecularColor::set(ColorValue::FromColor(Color::White));
			light1->Type = (LightType::Directional);
			light1->Diffuse::set(Color::White);
			light1->Direction::set(Vector3(0.0f, -1.0f, -1.00f));
			light1->Range::set(30.0f);

			// poni¿sza, wykomentowana czêœæ kodu dzia³a identycznie jak powy¿sze ustawienia œwiat³a "light1"
			//device->Lights[0]->Type::set(LightType::Directional);
			//device->Lights[0]->Diffuse::set(Color::AliceBlue);
			//device->Lights[0]->Direction::set(Vector3(1.0f,1.0f,-1.0f));
			//device->Lights[0]->Position::set(Vector3(-4.0f,-2.0f,-4.0f));
			//device->Lights[0]->Range::set(15.0f);

			device->Lights[0]->FromLight(light1);
			device->Lights[0]->Enabled = true;
			device->RenderState->Lighting = true;
			device->RenderState->ColorVertex::set(true);	//to powoduje brak koloru - gdy jest false
		}

		void UtworzObiekt() {


			linia_X = gcnew array<CustomVertex::PositionNormalColored>(2);
			linia_X[0] = CustomVertex::PositionNormalColored(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Color::Black.ToArgb());
			linia_X[1] = CustomVertex::PositionNormalColored(Vector3(8.0f, 0.0f, 0.0f), Vector3(8.0f, 0.0f, 0.0f), Color::Black.ToArgb());

			linia_Y = gcnew array<CustomVertex::PositionNormalColored>(2);
			linia_Y[0] = CustomVertex::PositionNormalColored(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Color::Red.ToArgb());
			linia_Y[1] = CustomVertex::PositionNormalColored(Vector3(0.0f, 8.0f, 0.0f), Vector3(0.0f, 8.0f, 0.0f), Color::Red.ToArgb());

			linia_Z = gcnew array<CustomVertex::PositionNormalColored>(2);
			linia_Z[0] = CustomVertex::PositionNormalColored(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Color::Green.ToArgb());
			linia_Z[1] = CustomVertex::PositionNormalColored(Vector3(0.0f, 0.0f, 8.0f), Vector3(0.0f, 8.0f, 0.0f), Color::Green.ToArgb());
			
			WriteGameOver();

			Pojemnik.Add_component(gcnew Enemy_Ships(Vector3(0, 0, 10.0f))); //dodanie pierwszego wrogiego statku
			Pojemnik.Add_component(gcnew Enemy_Ships(Vector3(0, 0, 15.0f))); //dodanie pierwszego wrogiego statku
			//Pojemnik.Add_component(gcnew Szescian(0.25f, Color::Blue.ToArgb(), Vector3(-2, 2, 12)));
			//Pojemnik.Add_component(1.5, Vector3(0, 0, 0), Color::Red.ToArgb());
			//Pojemnik.Add_component(0.5, Vector3(4, 3, 0), Color::Turquoise.ToArgb());

			//Pojemnik.Add_component(gcnew Czworoscian(0.9f,Color::Red.ToArgb(),Vector3(0,3,12)));
			//Pojemnik.Add_component(gcnew Walec(0.02f,1.0f, Color::Gold.ToArgb(), Vector3(-0.50f, 0.525f, 5.0f), -M_PI_2 ) );
			//Pojemnik.Add_component(0.5, Vector3(3, 0, 12), Color::LightSlateGray.ToArgb());
			//Pojemnik.Add_component(gcnew Kula(4, Vector3(-5, 2, 10), Color::LightGreen.ToArgb()));

			main_ship = gcnew Player_Ship(Vector3(0.20f, 0.0f, 0), 0.75f ,2); //dodanie do gry statku gracza
			celownik = gcnew array<CustomVertex::PositionNormalColored>(2); //dodanie celownika
			aim = main_ship->GetNosePosition();
			celownik[0] = CustomVertex::PositionNormalColored(main_ship->GetNosePosition(), main_ship->GetNosePosition(), Color::White.ToArgb());
			aim.Z += 20.0f;
			celownik[1] = CustomVertex::PositionNormalColored(aim, aim, Color::White.ToArgb());

			Shot_counter.Add_component(gcnew Digits_on_screen(0, Vector3(-3.05f, 0.0f, 0.0f), 0.5f, Color::Blue.ToArgb()));
			Shot_counter.Add_component(gcnew Digits_on_screen(0, Vector3(-2.85f, 0.0f, 0.0f), 0.5f, Color::Blue.ToArgb()));

			Level_sign.Add_component(gcnew Digits_on_screen(level_and_difficulty->GetLevel(), Vector3(2.85f, 0.0f, 0.0f), 0.5f, Color::Blue.ToArgb()));
			LVL = gcnew Letters_on_screen("LVL", Vector3(2.75f, 0.35f, 0.0f), 0.35f, Color::Black.ToArgb());
			
			difficulty_sign = gcnew Letters_on_screen("DIFFICULTY", Vector3(0.75f, 1.0f, 0.0f), 0.35f, Color::Black.ToArgb());
			Difficulty.Add_component(gcnew Letters_on_screen("Low", Vector3(1.35f, 0.60f, 0.0f), 0.35f, Color::Blue.ToArgb()));
			Difficulty.Add_component(gcnew Letters_on_screen("Medium", Vector3(1.05f, 0.60f, 0.0f), 0.35f, Color::Blue.ToArgb()));
			Difficulty.Add_component(gcnew Letters_on_screen("HIGH", Vector3(1.25f, 0.60f, 0.0f), 0.35f, Color::Blue.ToArgb()));

			Play_Again.Add_component(gcnew Letters_on_screen("Play Again", Vector3(-2.25f, 1.0f, 0.0f), 0.35f, Color::Black.ToArgb()));
			Play_Again.Add_component(gcnew Letters_on_screen("Enter", Vector3(-2.25f, 0.60f, 0.0f), 0.35f, Color::Blue.ToArgb()));
		}


		void Rysuj() {
			Redefine_View_and_perspective();

			Generate_Player_Shots();	//funkcja generuj¹ca strza³y ze statku gracza
			main_ship->Act_on_key_pressed(); //funkcja, która odpowiada za poruszanie statku gracza po ekranie za pomoc¹ przycisków

			device->Clear(ClearFlags::Target | ClearFlags::ZBuffer, Color::DarkGreen, 1.0f, 0); // wyczyœæ poprzedni¹ "klatkê" obrazu
			device->BeginScene();		//rozpocznij now¹ scenê
			device->VertexFormat = CustomVertex::PositionNormalColored::Format;  //zdefiniuj format macierzy u¿ywanej do wyœwietlania bry³
	
			
			//DrawCoordinateSystem();
			
			//wyrysuj strza³y ze statku gracza
			for (int i = 0; i < poj_na_strzaly.Get_licznik_bryl(); i++){
				device->DrawUserPrimitives(PrimitiveType::TriangleStrip, poj_na_strzaly.Set_current_pointer(i)->GetShapePtrLength(), poj_na_strzaly.Set_current_pointer(i)->GetShape());
			}

			//wyrysuj wszystkie obiekty z pojemnika obiektów
			for (int i = 0; i<Pojemnik.Get_licznik_bryl(); i++){
				if (dynamic_cast<Szescian^>(Pojemnik.Set_current_pointer(i)))
					device->DrawUserPrimitives(PrimitiveType::TriangleList, Pojemnik.Set_current_pointer(i)->GetShape()->Length / 3, Pojemnik.Set_current_pointer(i)->GetShape());
				else if (dynamic_cast<Kula^>(Pojemnik.Set_current_pointer(i)))
					device->DrawUserPrimitives(PrimitiveType::TriangleStrip, Pojemnik.Set_current_pointer(i)->GetShape()->Length - 3, Pojemnik.Set_current_pointer(i)->GetShape());
				else if (dynamic_cast<Czworoscian^>(Pojemnik.Set_current_pointer(i)))
					device->DrawUserPrimitives(PrimitiveType::TriangleList, Pojemnik.Set_current_pointer(i)->GetShape()->Length / 3, Pojemnik.Set_current_pointer(i)->GetShape());
				else if (dynamic_cast<Walec^>(Pojemnik.Set_current_pointer(i))){
					device->DrawUserPrimitives(PrimitiveType::TriangleStrip, Pojemnik.Set_current_pointer(i)->GetShape()->Length - 3, Pojemnik.Set_current_pointer(i)->GetShape());
				}
				else if (dynamic_cast<Enemy_Ships^>(Pojemnik.Set_current_pointer(i))){
					sh = (Enemy_Ships^)(Pojemnik.Set_current_pointer(i));
					sh->Act_on_key_pressed();
					device->DrawUserPrimitives(PrimitiveType::TriangleStrip, sh->Length()-1, sh->Get_ship());
				}
			}
			
			//wyrysuj strza³y ze statku wroga
			for (int i = 0; i < poj_na_strzaly_wroga.Get_licznik_bryl(); i++){
				device->DrawUserPrimitives(PrimitiveType::TriangleStrip, poj_na_strzaly_wroga.Set_current_pointer(i)->GetShapePtrLength(), poj_na_strzaly_wroga.Set_current_pointer(i)->GetShape());
			}

			//rysuj statek gracza
			if (GAME_OVER == false){
				device->DrawUserPrimitives(PrimitiveType::TriangleStrip, main_ship->Length() - 1, main_ship->Get_ship());
				DrawAimLine();
			}

			//rysuj licznik pokazuj¹cy aktualny level
			device->DrawUserPrimitives(PrimitiveType::TriangleStrip, LVL->GetShapePtrLength() - 1, LVL->GetShape());
			for (int i = 0; i < Level_sign.Get_licznik_bryl(); i++){
				device->DrawUserPrimitives(PrimitiveType::TriangleStrip, Level_sign.Set_current_pointer(i)->GetShapePtrLength()-1, Level_sign.Set_current_pointer(i)->GetShape());
			}

			//rysuj licznik pokazujacy liczbê zestrzelonych statkow
			for (int i = 0; i < Shot_counter.Get_licznik_bryl(); i++){
				device->DrawUserPrimitives(PrimitiveType::TriangleStrip, Shot_counter.Set_current_pointer(i)->GetShapePtrLength() - 1, Shot_counter.Set_current_pointer(i)->GetShape());
			}
			
			device->EndScene();
			device->Present();
			
		}//end of Rysuj()


		void Game_over_signal(){
			main_ship->ship_pointing_direction = -1;
			main_ship->MoveShapeTo(Vector3(0.0f, 0.5f, 1.5f));
			device->Clear(ClearFlags::Target | ClearFlags::ZBuffer, Color::Red, 1.0f, 0); // wyczyœæ poprzedni¹ "klatkê" obrazu
			device->BeginScene();		//rozpocznij now¹ scenê
			device->VertexFormat = CustomVertex::PositionNormalColored::Format;  //zdefiniuj format macierzy u¿ywanej do wyœwietlania bry³

			for (int i = 0; i < Sign_Game_Over.Get_licznik_bryl(); i++){
				if (dynamic_cast<Szescian^>(Sign_Game_Over.Set_current_pointer(i)))
					device->DrawUserPrimitives(PrimitiveType::TriangleList, Sign_Game_Over.Set_current_pointer(i)->GetShape()->Length / 3, Sign_Game_Over.Set_current_pointer(i)->GetShape());
			}

			device->DrawUserPrimitives(PrimitiveType::TriangleStrip, main_ship->Length() - 1, main_ship->Get_ship());

			device->DrawUserPrimitives(PrimitiveType::TriangleStrip, difficulty_sign->GetShapePtrLength()-1, difficulty_sign->GetShape());
			device->DrawUserPrimitives(PrimitiveType::TriangleStrip, Difficulty.Set_current_pointer(level_and_difficulty->GetDifficulty())->GetShapePtrLength() - 1, Difficulty.Set_current_pointer(level_and_difficulty->GetDifficulty())->GetShape());
			
			for (int i = 0; i < Play_Again.Get_licznik_bryl(); i++){
				device->DrawUserPrimitives(PrimitiveType::TriangleStrip, Play_Again.Set_current_pointer(i)->GetShapePtrLength()-1, Play_Again.Set_current_pointer(i)->GetShape());
			}

			device->EndScene();
			device->Present();
		}//end of Game_over_signal()


		void Rotate_after_game_over(){
			Redefine_View_and_perspective();

			device->Clear(ClearFlags::Target | ClearFlags::ZBuffer, Color::DarkGreen, 1.0f, 0); // wyczyœæ poprzedni¹ "klatkê" obrazu
			device->BeginScene();		//rozpocznij now¹ scenê
			device->VertexFormat = CustomVertex::PositionNormalColored::Format;  //zdefiniuj format macierzy u¿ywanej do wyœwietlania bry³

			//wyrysuj wszystkie obiekty z pojemnika obiektów
			for (int i = 0; i<Pojemnik.Get_licznik_bryl(); i++){
				if (dynamic_cast<Enemy_Ships^>(Pojemnik.Set_current_pointer(i))){
					sh = (Enemy_Ships^)(Pojemnik.Set_current_pointer(i));
					sh->Act_on_key_pressed();
					device->DrawUserPrimitives(PrimitiveType::TriangleStrip, sh->Length() - 1, sh->Get_ship());
				}
			}

			device->DrawUserPrimitives(PrimitiveType::TriangleStrip, main_ship->Length() - 1, main_ship->Get_ship());
			DrawAimLine();
			
			device->EndScene();
			device->Present();
		}//end of Rotate_after_game_over()

#pragma endregion


	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		obrot += 0.01f;
		keyboard1->Update_global_time(obrot);	//Uaktualnienie czasu w klasie obs³uguj¹cej klawiaturê - potrzebne do generowania ci¹g³ego strza³u z odpowiednim odstêpem

		if (GAME_OVER == false)
		try{
			Delete_Intersecting_Objects();  //funkcja usuwaj¹ca obiekty, które siê ze sob¹ zderzy³y (nie dotyczy strza³ów gracza zderzonych ze strza³ami wroga)
			Move_or_delete_components(); //Funkcja przesuwa obiekty na ekranie o odpowiednie wielkoœci
			Rysuj();
		}
		catch (...){
			GAME_OVER = true;
		}
		else
			Game_over_signal();
			//Stop_Enemy_Ship_Movement();
			//Rotate_after_game_over();

	}// end of timer1_Tick()

	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		//W tej funkcji generowane s¹ strza³y wrogich statków, dodawane i przesuwane s¹ statki wroga
		try{
			if (GAME_OVER == false){
				Add_Enemy_Ship();
				Generate_Enemy_Shots();	
				Move_Enemy_Ship();
			}
			
		}
		catch (...){
			GAME_OVER = true;
		}
	}// end of timer2_Tick()


	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		obrot = 0;
	}//end of Form1_Load()

	private: System::Void Form1_Resize(System::Object^ sender, System::EventArgs^ e){
		if (device != nullptr){
			Control^ control = dynamic_cast<Control^>(sender);
			Resizing_window(control->Size.Width, control->Size.Height);
		}
	}//end of Form1_Resize()

	private: System::Void Form1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){
		//TODO miejsce na kod dla przesuwania myszy
	}//end of Form1_MouseMove

	private: System::Void Form1_Mouse_LClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){
		//TODO miejsce na kod dla lewego klikniêcia mysz¹
		if (GAME_OVER == true){
			OnGameResume();
		}
	}//end of Form1_Mouse_LClick()

	private: System::Void Form1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e){
		keyboard1->Act_on_key_pressed(e);
	}//end of Form1_KeyPress()	

	private: System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e){
		keyboard1->Act_on_key_down(e);
		main_ship->Act_on_key_down(e);

		if (e->KeyCode == Keys::Enter && GAME_OVER == true){
			OnGameResume();
		}
		
		if (GAME_OVER == true){
			if (e->KeyCode == Keys::Right){
				level_and_difficulty->SetDifficulty(level_and_difficulty->GetDifficulty() + 1);
			}
			else if (e->KeyCode == Keys::Left){
				level_and_difficulty->SetDifficulty(level_and_difficulty->GetDifficulty() - 1);
			}
		}
	}//end of Form1_KeyDown()
	
	private: System::Void Form1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
		keyboard1->Act_on_key_up(e);
		main_ship->Act_on_key_up(e);
	}//end of Form1_KeyUp()


	private: void DrawCoordinateSystem(){
		device->DrawUserPrimitives(PrimitiveType::LineList, linia_X->Length/2, linia_X);
		device->DrawUserPrimitives(PrimitiveType::LineList, linia_Y->Length/2, linia_Y);
		device->DrawUserPrimitives(PrimitiveType::LineList, linia_Z->Length/2, linia_Z);
	}

	private: void Delete_Intersecting_Objects(){
		int de[3] = { NULL, NULL, NULL };
		int dd[3] = { NULL, NULL, NULL };
		int counter = 0;
		int counter2 = 0;
		for (int i = 0; i < poj_na_strzaly.Get_licznik_bryl(); i++){
			for (int j = 0; j < Pojemnik.Get_licznik_bryl(); j++){
				if (dynamic_cast<Enemy_Ships^>(Pojemnik.Set_current_pointer(j)))
					if (detect_intrsc.CalculateForShoting(poj_na_strzaly.Set_current_pointer(i)->GetIntersectionPoints(), Pojemnik.Set_current_pointer(j)->GetIntersectionPoints())){
						if (counter != 3)
							de[counter++] = j + 1;
						if (counter2 != 3)
							dd[counter2++] = i + 1;
					}
			}
		}
		for (int i = 0; i < 3; i++){
			if (de[i] != 0){
 				Pojemnik.Delete_component(de[i] - 1);
				level_and_difficulty->AddShipsShotedCounter();
				UpdatePlayerShipShotsCounter();
			}
			if (dd[i] != 0)
				poj_na_strzaly.Delete_component(dd[i] - 1);
		}

		counter = 0;
		for (int i = 0; i < poj_na_strzaly_wroga.Get_licznik_bryl(); i++){
			if (detect_intrsc.CalculatePlayerShipForShoting(poj_na_strzaly_wroga.Set_current_pointer(i)->GetIntersectionPoints(), main_ship->GetIntersectionPoints())){
				//if (counter != 3)
				//	dd[counter++] = i + 1;
				GAME_OVER = true;
			}
		}
		//for (int i = 0; i < 3; i++){
		//	if (dd[i] != 0){
		//		//Shot^ shot1 = (Shot^)(poj_na_strzaly_wroga.Set_current_pointer(dd[i]-1));
		//		poj_na_strzaly_wroga.Delete_component(dd[i] - 1);
		//	}
		//}
		dd[0] = 0;
		for (int i = 0; i < Pojemnik.Get_licznik_bryl(); i++){
			if (detect_intrsc.CalculateForHitingPlayerShip(main_ship->GetIntersectionPoints(), Pojemnik.Set_current_pointer(i)->GetIntersectionPoints())){
				GAME_OVER = true;
				dd[0] = i + 1;
				break;
			}
		}
		if (dd[0] != 0)
			Pojemnik.Delete_component(dd[0] - 1);

		if (level_and_difficulty->UpdateLevel() == true){
			UpdateLevel();
		}
	}//end of Delete_Intersecting_Objects()

	private: void Move_or_delete_components(){
		int del = 0;
		for (int i = 0; i < Pojemnik.Get_licznik_bryl(); i++){
			if (dynamic_cast<Enemy_Ships^>(Pojemnik.Set_current_pointer(i))){
				Pojemnik.Set_current_pointer(i)->MoveShape(Vector3(0, 0, -level_and_difficulty->GetEnemyShipsMovingSpeed() ) );
			}
			else
				Pojemnik.Set_current_pointer(i)->MoveShape(Vector3(0, 0, -level_and_difficulty->GetOtherShapesMovingSpeed() ) );
			
			if (Pojemnik.Set_current_pointer(i)->GetPosition().Z < -1.0f)
				del = i + 1;
		}
		if (del != 0)
			Pojemnik.Delete_component(del - 1);


		del = 0;
		for (int i = 0; i < poj_na_strzaly.Get_licznik_bryl(); i++){
			poj_na_strzaly.Set_current_pointer(i)->MoveShape(Vector3(0, 0, level_and_difficulty->GetPlayerShotsSpeed() ) );
			if (poj_na_strzaly.Set_current_pointer(i)->GetPosition().Z > far_plane - 1.0f)
				del = i + 1;
		}
		if (del!=0)
			poj_na_strzaly.Delete_component(del-1);

		del = 0;
		for (int i = 0; i < poj_na_strzaly_wroga.Get_licznik_bryl(); i++){
			poj_na_strzaly_wroga.Set_current_pointer(i)->MoveShape(Vector3(0, 0, -level_and_difficulty->GetEnemyShipsShotsSpeed() ) );
			if (poj_na_strzaly_wroga.Set_current_pointer(i)->GetPosition().Z < -1.0f)
				del = i + 1;
		}
		if (del!=0)
			poj_na_strzaly_wroga.Delete_component(del-1);

	}//end of Move_or_delete_components()

	private: void Add_Enemy_Ship(){
		if (Pojemnik.Get_licznik_bryl() < level_and_difficulty->GetMaximalNumberOfEnemyShips() ){
			int coord_syst_part = rand() % 2;
			int coord_x = rand() % 25;
			int coord_y = rand() % 28;

			if (Pojemnik.Get_licznik_bryl() > level_and_difficulty->GetWhenRandomGenerateEnemyShips()){
				int rr = rand() % level_and_difficulty->GetProbabilityOfAddingEnemyShip();
				if (rr == 1){
					if (coord_syst_part == 1)
						Pojemnik.Add_component(gcnew Enemy_Ships(Vector3((float)(coord_x / 10), (float)(coord_y / 10), 20.0f)));
					else if (coord_syst_part == 0)
						Pojemnik.Add_component(gcnew Enemy_Ships(Vector3((float)(-coord_x / 10), (float)(coord_y / 10), 20.0f)));
				}
			}
			else{
				if (coord_syst_part == 1)
					Pojemnik.Add_component(gcnew Enemy_Ships(Vector3((float)(coord_x / 10), (float)(coord_y / 10), 20.0f)));
				else if (coord_syst_part == 0)
					Pojemnik.Add_component(gcnew Enemy_Ships(Vector3((float)(-coord_x / 10), (float)(coord_y / 10), 20.0f)));
			}
		}
	} // end of  Add_Enemy_Ship()

	private: void Move_Enemy_Ship(){
		if (Pojemnik.Get_licznik_bryl() != 0){
			int move = rand() % level_and_difficulty->GetEnemyShipsMovingAbility();
			int r = rand() % Pojemnik.Get_licznik_bryl();
			sh = (Enemy_Ships^)(Pojemnik.Set_current_pointer(r));
			sh->RandomShipMove(move);
		}
	}//end of Move_Enemy_Ship()

	private: void Stop_Enemy_Ship_Movement(){
		for (int i = 0; i < Pojemnik.Get_licznik_bryl(); i++){
			sh = (Enemy_Ships^)(Pojemnik.Set_current_pointer(i));
			sh->RandomShipMove(0);
		}
	}

	private: void Generate_Enemy_Shots(){
		for (int i = 0; i < Pojemnik.Get_licznik_bryl(); i++){
			if (dynamic_cast<Enemy_Ships^>(Pojemnik.Set_current_pointer(i))){
				if (poj_na_strzaly_wroga.Get_licznik_bryl() < level_and_difficulty->GetMaximalNumberOfEnemyShots() ){
					int rr = rand() % level_and_difficulty->GetProbabilityOfGeneratingEnemyShot();
					if (rr == 1){
						sh = (Enemy_Ships^)(Pojemnik.Set_current_pointer(i));
						poj_na_strzaly_wroga.Add_component(gcnew Shot(sh->GetNosePosition(), Color::Red.ToArgb() + 20));
					}
				}
			}
		}
	}//end of Generate_Enemy_Shots()

	private: void Generate_Player_Shots(){
		keyboard1->CheckForConstantShot();
		if (keyboard1->Shot() == true){
			if (keyboard1->GetShotConstant() == true){
				if (obrot - level_and_difficulty->GetMinimalTimeBeetwenPlayerShots() > keyboard1->GetTimeOfLastShot()){
					poj_na_strzaly.Add_component(gcnew Shot(main_ship->GetNosePosition()));
					keyboard1->ShotDone();
				}
			}
			else{
				poj_na_strzaly.Add_component(gcnew Shot(main_ship->GetNosePosition()));
				keyboard1->ShotOnceDone();
			}
		}
	}// end of Generate_Player_Shots()
	
	private: void Redefine_View_and_perspective(){
		if (keyboard1->GetUpdateStatus()){
			device->Transform->View = Matrix::LookAtLH(keyboard1->Get_view_position(), keyboard1->Get_view_focus(), keyboard1->Get_view_up_direction());
			device->Transform->Projection = Matrix::PerspectiveFovLH(perspective_field_of_view, ((float)ClientSize.Width / ClientSize.Height), 1.0f, far_plane);
			keyboard1->ScreenUpdated();
		}
	}

	private: void WriteGameOver(){
		//main_ship->Move_Ship(Vector3(0, 0, 0));

		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-2.8f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-2.6f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-3.0f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-3.2f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-3.2f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-3.2f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-3.2f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-3.0f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-2.8f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-2.6f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.20f, Color::Black.ToArgb(), Vector3(-2.6f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.15f, Color::Black.ToArgb(), Vector3(-2.7f, 2.425f, 1.0f)));
		//Literka G - koniec
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-2.2f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-2.2f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-2.2f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-2.2f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-2.0f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-1.8f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-2.0f, 2.5f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-1.8f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-1.8f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-1.8f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-1.8f, 2.8f, 1.0f)));
		//Literka A - koniec

		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-1.45f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-1.45f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-1.45f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-1.45f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.15f, Color::Black.ToArgb(), Vector3(-1.32f, 2.7f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.15f, Color::Black.ToArgb(), Vector3(-1.25f, 2.67f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.15f, Color::Black.ToArgb(), Vector3(-1.175f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.15f, Color::Black.ToArgb(), Vector3(-1.15f, 2.65f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.15f, Color::Black.ToArgb(), Vector3(-1.01f, 2.7f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.90f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.90f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.90f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.90f, 2.2f, 1.0f)));
		//Literka M - koniec

		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.55f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.55f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.55f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.55f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.35f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.15f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.15f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.35f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(-0.35f, 2.5f, 1.0f)));
		//literka E - koniec

		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(0.55f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(0.55f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(0.55f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(0.55f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(0.75f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(0.75f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(0.95f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(0.95f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(0.95f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(0.95f, 2.8f, 1.0f)));
		//literka O - koniec

		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.35f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.3f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.25f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.20f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.45f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.5f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.55f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.60f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.65f, 2.8f, 1.0f)));
		//literka V - koniec

		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.95f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.95f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.95f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(1.95f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.15f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.35f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.35f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.15f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.15f, 2.5f, 1.0f)));
		//literka E - koniec

		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.75f, 2.2f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.75f, 2.4f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.75f, 2.6f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.75f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.95f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(3.15f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(3.25f, 2.8f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(2.95f, 2.5f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(3.15f, 2.5f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.2f, Color::Black.ToArgb(), Vector3(3.25f, 2.5f, 1.0f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.1f, Color::Black.ToArgb(), Vector3(3.25f, 2.55f, 0.88f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.1f, Color::Black.ToArgb(), Vector3(3.25f, 2.65f, 0.88f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.1f, Color::Black.ToArgb(), Vector3(3.20f, 2.4f, 0.88f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.1f, Color::Black.ToArgb(), Vector3(3.20f, 2.3f, 0.88f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.1f, Color::Black.ToArgb(), Vector3(3.26f, 2.2f, 0.88f)));
		Sign_Game_Over.Add_component(gcnew Szescian(0.1f, Color::Black.ToArgb(), Vector3(3.26f, 2.13f, 0.88f)));
		//literka R - koniec
	}

	private: void DrawAimLine(){
		aim = main_ship->GetNosePosition();
		float Z_add=0;
		int color = Color::DarkGoldenrod.ToArgb();
		for (int i = 0; i < Pojemnik.Get_licznik_bryl(); i++){
			intersect_aim = Pojemnik.Set_current_pointer(i)->GetIntersectionPoints();
			for (int j = 0; j < intersect_aim->Length; j+=2){
				if (aim.X >= intersect_aim[j].X - intersect_aim[j + 1].X && aim.X <= intersect_aim[j].X + intersect_aim[j + 1].X)
					if (aim.Y >= intersect_aim[j].Y && aim.Y <= intersect_aim[j].Y + intersect_aim[j + 1].Y){
						color = Color::Red.ToArgb();
						if (intersect_aim[j].Z>2.0f)
							if (Z_add==0)
								Z_add = intersect_aim[j].Z;
							else{
								if (intersect_aim[j].Z<Z_add)
									Z_add = intersect_aim[j].Z;
							}
					}	
			}
		}
		celownik[0] = CustomVertex::PositionNormalColored(aim, aim, color);
		if (Z_add == 0){
			Z_add = 3.0f;
		}
		aim.Z = Z_add;
		celownik[1] = CustomVertex::PositionNormalColored(aim, aim, color);
		device->DrawUserPrimitives(PrimitiveType::LineList, celownik->Length / 2, celownik);
	}

	private: void OnGameResume(){
		poj_na_strzaly_wroga.RemoveAllComponents();
		poj_na_strzaly.RemoveAllComponents();
		Pojemnik.RemoveAllComponents();

		main_ship->ship_pointing_direction = 1;
		main_ship->MoveShapeTo(Vector3(0.0f, 0.50f, 0.0f));

		
		if (previous_difficulty != level_and_difficulty->GetDifficulty()){
			level_and_difficulty->SetLevel(1);
			level_and_difficulty->ResetShipsShotedCounter();
			previous_difficulty = level_and_difficulty->GetDifficulty();
		}
		else
			level_and_difficulty->UpdateOnGameOver();

		UpdateLevel();
		UpdatePlayerShipShotsCounter();

		GAME_OVER = false;
	}

	private: void UpdatePlayerShipShotsCounter(){
		if (level_and_difficulty->GetShipsShotedCounter()>9){
			Shot_counter.Delete_component(1);
			Shot_counter.Delete_component(0);
			int shot_counter = level_and_difficulty->GetShipsShotedCounter();
			int tens = (shot_counter - shot_counter % 10) / 10;
			Shot_counter.Add_component(gcnew Digits_on_screen(tens, Vector3(-3.05f, 0.0f, 0.00f), 0.50f, Color::Blue.ToArgb()));
			Shot_counter.Add_component(gcnew Digits_on_screen(shot_counter % 10, Vector3(-2.85f, 0.0f, 0.00f), 0.5f, Color::Blue.ToArgb()));
		}
		else{
			Shot_counter.Delete_component(1);
			Shot_counter.Delete_component(0);
			Shot_counter.Add_component(gcnew Digits_on_screen(level_and_difficulty->GetShipsShotedCounter(), Vector3(-2.85f, 0.0f, 0.00f), 0.5f, Color::Blue.ToArgb()));
			Shot_counter.Add_component(gcnew Digits_on_screen(0, Vector3(-3.05f, 0.0f, 0.00f), 0.50f, Color::Blue.ToArgb()));
		}
	}

	private: void UpdateLevel(){
		Level_sign.Delete_component(0);
		Level_sign.Add_component(gcnew Digits_on_screen(level_and_difficulty->GetLevel(), Vector3(2.85f, -0.1f, 0.00f), 0.50f, Color::Blue.ToArgb()));
	}
};
}

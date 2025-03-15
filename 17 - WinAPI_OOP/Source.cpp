#include <wapi_oop.h>
#include <cmath>

float xFormula(const float x, const float y, const float z, const float h)
{
	return x + h * 10 * (y - x);
}

float yFormula(const float x, const float y, const float z, const float h)
{
	return y + h * (x * (28 - z) - y);
}

float zFormula(const float x, const float y, const float z, const float h)
{
	return z + h * (x * y - 8 / 3 * z);
}


void schizophrenia(std::vector<float>& xVec, std::vector<float>& zVec)
{
	float x = 4, y = -2, z = 0;
	const float h = 0.01;
	const uint16_t N = 1000;

	for (int i = 0; i < N; i++)
	{
		float x2 = xFormula(x, y, z, h);
		float y2 = yFormula(x, y, z, h);
		float z2 = zFormula(x, y, z, h);

		x = x2; y = y2; z = z2;

		xVec.emplace_back(x * 5);
		zVec.emplace_back(z * 5);
	}
}

// Класс нового окна наследуется от абстракного окна
class MainWindow : public Window
{
	// Для использования внутри окна других графических
	// объектов используется std::unique_ptr
	std::unique_ptr<PaintBox> pb;

public:
	MainWindow(HINSTANCE hInstance) : Window(hInstance)
	{
		// Основное окно не имеет родителя
		// Этот метод вызывается первым
		InitComponent(nullptr);

		// Инициализация вложенных полей
		pb = std::make_unique<PaintBox>(hInstance, 1, this);

		// Установка свойств полей
		pb->SetPosition(10, 10);
		pb->SetSize(512, 512);

		// Установка свойств окна
		SetSize(550, 570);
		SetText(L"Painting in C++");
		SetStyle(WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME);
	}
	~MainWindow() = default;

	// OYHKUHN OTPHCOBKH
	void Draw()
	{
		int N = 1000;
		std::vector<float> xVec = {20};
		std::vector<float> zVec = {0};
		pb->SetPen(PaintBox::Solid, 1, { 0, 0, 255 });
		schizophrenia(xVec, zVec);
		for (int i = 1; i <= N; ++i)
		{
			std::vector<int> coords = { (int)xVec[i - 1]+100, (int)zVec[i - 1] + 100, (int)xVec[i] + 100, (int)zVec[i] + 100 };
			pb->Draw<Figure::LINE>(coords);
		}
		pb->Update();
	}

protected:
	// Обязательно определяем имя класса
	DECLARE_CLASS_NAME(MainWindow)
};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrev, PWSTR cmdLine, int nCmdShow)
{
	// Регистрация класса PaintBox
	REGISTER_DEFAULT(hInstance);

	// Регистрация основного окна
	RegisterControl(MainWindow, hInstance);

	MainWindow mw(hInstance);
	mw.Show();
	mw.Draw();

	mw.ProcessMessages();

	return 0;
}
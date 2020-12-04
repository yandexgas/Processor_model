#pragma once
#include <iostream>
#include<stdexcept>

	
namespace gya {
	/*!
	\brief Шаблон итератора для  контейнерного  класса vector, работающего с динамическим массивом.
	Экземпляры данного класса дают последовательный доступ элементам класса vector.
*/
	template <class ARG>
	class Itvector {
	private:
		ARG* ptr;
	public:
		/*!
	\brief Конструктор по умолчанию для данного класса
*/
		Itvector() : ptr(nullptr) {};
		/*!
	\brief Инициализирующий конструктор
	Инициализирует итератор значением ячейки памяти, в которой хранится текущий элемент массива vector
*/
		Itvector(ARG* a) : ptr(a) {};
		/*!
	\brief Перегруженный оператор сравнения
	\param a ссылка на другой экземпляр данного класса
	Сравнивает указатели на элементы массива vector для двух итераторов, в случае равенства считается что итераторы равны.
*/
		bool operator == (const Itvector <ARG>& a) { return ptr == a.ptr; };
		/*!
	\brief Перегруженный оператор неравенства
	\param a ссылка на другой экземпляр данного класса
	Сравнивает указатели на элементы массива vector для двух итераторов, в случае их отличия считается что итераторы не равны.
*/
		bool operator != (const Itvector <ARG>& a) { return ptr != a.ptr; };
		/*!
	\brief Перегруженный оператор разыменовывания
	Помогает работать с итератором как с указателем, примененный к итератору , возвращает значение указателя на текущий элемент vector'a
*/
		ARG& operator * () { return *ptr; }
		ARG* operator ->() { return ptr; }
		/*!
	\brief Перегруженный префиксный оператор инкремента
	Примененный к итератору дает доступ к значению следующего элемента в массиве vector	*/
		Itvector<ARG>& operator ++() { ++ptr; return *this; };
		/*!
	\brief Перегруженный постфиксный оператор инкремента
	Примененный к итератору дает доступ к значению текущего элемента в массиве vector, а затем перемещает указатель на следующее значение	*/
		Itvector<ARG> operator ++(int) { Itvector<ARG> res(*this); ++ptr; return res; }

	};
	/*!
	\brief Шаблон контейнерного vector, работающего с динамическим массивом.
	контейнерый класс позволяющий хранить однотипные объекты любого типа данных, выделение памяти происходит динамически
*/
	template < class ARG>
	class vector {
	private:
		const int quot = 15;
		int sz, now_max_size;
		ARG* array;
		friend Itvector<ARG>;
		void resize() {
			int i = check_size();
			if (i == -1) {
				ARG* ar2 = new ARG[sz + 2];
				now_max_size = sz + 2;
				for (int k = 0;k < sz;k++) {
					ar2[k] = array[k];
				}
				delete[] array;
				array = ar2;
			}
			if (i == 1) {
				ARG* ar2 = new ARG[sz + quot];
				now_max_size = sz + quot;
				for (int k = 0;k < sz;k++) {
					ar2[k] = array[k];
				}
				delete[] array;
				array = ar2;
			}
		}
		int check_size() {
			if (now_max_size - sz > quot + 1)
				return -1;
			if (sz == now_max_size)
				return 1;
			return 0;
		}
	public:
		/*!
	\brief Дефолтный конструктор, создает пустой вектор
	при этом размер вектора становится нулевым, а память уже выделяется в размере квоты (по умолчанию 15 элементов)
	*/
		vector() :sz(0), now_max_size(quot) { array = new ARG[quot]; }
		/*!
		
	\brief Конструктор для инициализации класса vector указателем на область памяти, в которой уже хранятся элементы
	\param ar указатель на область памяти в которой последовательно расположены элементы типа ARG
	соответствующие типу данного вектора. Происходит копирование самих элементов из той области памяти в вектор, а не копирование указателя
	size вектора будет равен количеству элементов в области памяти, now_max_size = size, т.о. при добавлении элемента в следующий раз выделится память в размере квоты.
	*/
		vector(ARG* ar) {
			int i = (_msize(ar) / sizeof(ARG));
			array = new ARG[i];
			sz = i;
			now_max_size = i;
			for (int k = 0;k < i;k++)
				array[k] = ar[k];
		}
		/*!
	\brief Копирующий  конструктор, копирует один вектор в данный
	\param a ссылка на вектор который будет копироваться
	элементы копируются по значениям, а не по указателям, size = now_max_size = количеству элементов
	*/
		vector(vector<ARG>& a) :sz(a.sz), now_max_size(a.sz) {
			auto it = a.begin();
			array = new ARG[sz];
			int i = 0;
			for (it;it != a.end();it++) {
				array[i] = *it;
				i++;
			}
		}
		/*!
	\brief Перемещающий  конструктор, перемещает указатель на данные из одного вектора в данный
	\param a ссылка на вектор из которого происходит перемещение
	значения длины вектора и текущей выделенной памяти как у параметра а, происходит копирование указателя из а в создаваемый экземпляр, после 
	чего в векторе а указатель заменяется на нулевой
	\warning экземпляр класса а становится непригодным для использования после перемещения данных
	*/
		vector(vector<ARG>&& a) :sz(a.sz), now_max_size(a.now_max_size), array(a.array) { a.array = nullptr; }
		/*!
	\brief Метод определяет пуст ли вектор
	\return логическое значение истины если вектор пуст (длина = 0) иначе - ложь
	*/
		bool empty() const { return sz == 0; }
		/*!
	\brief Функция определения длины вектора
	\return значение текущей длины вектора
	Данная функция эквивалентна функции length
	*/
		int size() const { return sz; }
		int length() const { return sz; }
		/*!
	\brief Функция очистки вектора
	\return ссылку на экзмпляр данного объекта
	обнуляет длину вектора, элементы же остаются как мусор, если мусора слишком много, вызывается метод компрессии
	\throw std::out_of_range если вектор пуст
	*/
		vector<ARG>& clear() { sz = 0; resize();return*this; }
		/*!
	\brief Функция помещает элемент в конец вектора
	\param val значение копируется в конец вектора
	\return ссылка на данный экземпляр вектоа
	если в векторе есть совбодное место - вставляет объект в конец вектора, если нет - перераспределяет память и выделяет дополнительную 
	в размере квоты, длина вектора увеличивается на 1
	\warning при слишком больших значениях длины вектора может закончиться память на вашем устройстве и функция не сможет быть выполнена
	*/
		vector<ARG>& push_back(const ARG& val) {
			resize();
				array[sz] = val;
				sz++;
			return *this;
		}
		/*!
	\brief Функция извлекает последний элемент вектора
	\return ссылку на константный объект типа данного шаблона
	размер вектора уменьшается на 1, сам элемент остается в нем как мусор, если мусора слишком много происходит освобождение памяти, после чего
	в векторе остается только 2 свободных места, вместо, например, 17
	\throw std::out_of_range если вектор пуст
	*/
		const ARG& pop_back() {
			if (!(this->empty())) {
				resize();
				sz--;
				return array[sz];
			}
			else throw std::out_of_range("vector is empty");
		}
		/*!
	\brief Оператор индексирования для r-value
	\param i  индекс по которому осуществляется доступ к элементу вектора
	\return ссылку на константное значение соответствующее индексу
	\throw std::out_of_range если вектор пуст, если значение индекса меньше нуля либо если больше длины вектора
	*/
		const ARG& operator [](int i) const {
			if (i >= sz)
				throw std::out_of_range("too big index");
			if (i < 0)
				throw std::out_of_range("invalid index");
			return array[i];
		}
		/*!
	\brief Оператор индексирования для l-value
	\param i  индекс по которому осуществляется доступ к элементу вектора
	\return ссылку на константное значение соответствующее индексу
	\throw std::out_of_range если вектор пуст, если значение индекса меньше нуля либо если больше длины вектора
	*/
		ARG& operator [](int i) {
			if (i >= sz)
				throw std::out_of_range("too big index");
			if (i < 0)
				throw std::out_of_range("invalid index");
			return array[i];
		}
		/*!
	\brief копирует вектор - аргумент в текущий экземпляр
	\param a ссылка на копируемый экземпляр
	\return ссылка на текущий экземпляр
	\warning старая информация, хранящаяся в векторе В КОТОРЫЙ копируют - теряется
	происходит копирование элементов по значениям, а не по указателям
	*/
		vector<ARG>& operator = (const vector<ARG>& a) {
			if (&a != this) {
				delete[] array;
				sz = a.sz;
				now_max_size = a.sz;
				array = new ARG[sz];
				for (int i = 0;i < sz;i++)
					array[i] = a.array[i];
			}
			return *this;
		}
		/*!
	\brief перемещает данные из  вектор - аргумент в текущий экземпляр
	\param a ссылка на перемещаемый экземпляр
	\return ссылка на текущий экземпляр
	\warning старая информация, хранящаяся в векторе В КОТОРЫЙ копируют - теряется, вектрый информацию из которого переместили становистся пустым
	происходит копирование указателя.
	*/
		vector<ARG>& operator = (const vector<ARG>&& a) {
			if (&a != this) {
				delete[] array;
				sz = a.sz;
				now_max_size = a.now_max_size;
				array = a.array;
				a.array = nullptr;
			}
			return*this;
		}
		typedef Itvector<ARG> Iterator;
		/*!
	\return экземпляр итератора соответствующий начальному значению вектора
	*/
		Iterator begin() const { return array; }
		/*!
		\return экземпляр итератора находящийся за пределами вектора
		*/
		Iterator end() const { return array+sz; }
		/*!
		\param i значение положения итератора который требуется получить
		\return экземпляр итератора находящийся на позиции поданного аргумента
		\throw std::out_of_range если параментр меньше нуля либо больше размера вектора
		*/
		Iterator find(int i) {
			if (i >= sz)
				throw std::out_of_range("too big index");
			if (i < 0)
				throw std::out_of_range("invalid index");
			return array+i;}
		/*!
	\brief деструктор 
	освобождает память выделенную под данные
	*/
		~vector() { delete[] array; };
	};
}


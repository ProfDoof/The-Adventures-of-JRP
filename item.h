#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Character;

class Item {
	private:
        std::string _Name;
        std::string _Description;
		int _Damage;
		int _Healing;
		
	public:
		Item(std::string Nam, std::string Desc, int Dam, int Heal) : _Name(Nam), _Description(Desc), _Damage(Dam), _Healing(Heal) {}
		
		//Getters and Setters
		void Name(std::string N) { _Name = N; }
        std::string Name() { return _Name; }
		void Description(std::string D) { _Description = D; }
        std::string Description() { return _Description; }
		void Damage(int K) { _Damage = K; }
		int Damage() const { return _Damage; }
		void Healing(int H) { _Healing = H; }
		int Healing() const { return _Healing; }
		class Error {
			private:
                std::string desc;
			public:
				Error(std::string description) : desc(description) {}
		};
};

class Curio {
	private:
		int something;
};
#endif

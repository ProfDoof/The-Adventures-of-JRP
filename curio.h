#ifndef CURIO_H
#define CURIO_H
#include <string>

class Curio {
	private:
		std::string _Name;
		std::string _Description;
		std::string _ItemUsed;
		std::string _ComDesc;
	public:
		Curio(std::string N, std::string D, std::string I, std::string C) : _Name(N), _Description(D), _ItemUsed(I), _ComDesc(C) {}
		void Name(std::string N) { _Name = N; }
        std::string Name() { return _Name; }
		void Description(std::string D) { _Description = D; }
        std::string Description() { return _Description; }
        void ItemUsed(std::string I) { _ItemUsed = I; }
        std::string ItemUsed() { return _ItemUsed; }
        void ComDesc(std::string I) { _ComDesc = I; }
        std::string ComDesc() { return _ComDesc; }
};

#endif
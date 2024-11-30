#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():  AForm("default", 145, 137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), _target(obj._target) {*this = obj;}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj){
	if (this != &obj){
		this->_target = obj._target;}
	return (*this);}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if(this->getIsSigned() == false){
		throw AForm::SignedException();}
	else if (executor.getGrade() > this->getGradeToExecute()){
		throw AForm::GradeTooLowException();}
	else
	{
		std::ofstream   file;
		std::string tree;

		tree = 
"                                                 .\n"
"                                      .         ;  \n"
"         .              .              ;%     ;;   \n"
"           ,           ,                :;%  %;   \n"
"            :         ;                   :;%;'     .,   \n"
"   ,.        %;     %;            ;        %;'    ,;\n"
"     ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"      %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"       ;%;      %;        ;%;        % ;%;  ,%;'\n"
"        `%;.     ;%;     %;'         `;%%;.%;'\n"
"         `:;%.    ;%%. %@;        %; ;@%;%'\n"
"            `:%;.  :;bd%;          %;@%;'\n"
"              `@%:.  :;%.         ;@@%;'   \n"
"                `@%.  `;@%.      ;@@%;         \n"
"                  `@%%. `@%%    ;@@%;        \n"
"                    ;@%. :@%%  %@@%;       \n"
"                      %@bd%%%bd%%:;     \n"
"                        #@%%%%%:;;\n"
"                        %@@%%%::;\n"
"                        %@@@%(o);  . '         \n"
"                        %@@@o%;:(.,'         \n"
"                    `.. %@@@o%::;         \n"
"                       `)@@@o%::;         \n"
"                        %@@(o)::;        \n"
"                       .%@@@@%::;         \n"
"                       ;%@@@@%::;.          \n"
"                      ;%@@@@%%:;;;. \n"
"                  ...;%@@@@@%%:;;;;,..    \n";
		file.open(this->_target + "_shrubbery");
		if(!file)
			std::cout << "Error: Failed to open" << std::endl;
		file << tree;
		file.close();
	}
}
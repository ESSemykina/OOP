#include "FileUserRepository.h"
#include "UserManager.h"

int main() 
{
    setlocale(LC_ALL, "Russian");  

    std::string filePath = "users.txt";

    std::unique_ptr<IUserRepository> userRepository(new FileUserRepository(filePath));

    std::unique_ptr<UserManager> userManager(new UserManager(userRepository.get()));

    User user(1, "KatyaSemykina", "password12345", "Test");

    userManager->signIn(user);

    std::cout << user.getLogin() << '\n';

    bool isAuthorized = userManager->isAuthorized();
    if (isAuthorized)
    {
        
        std::cout << "User is authorized" << std::endl;
    }
    else {
     
        std::cout << "User is not authorized" << std::endl;
    }

    userManager->signOut(user);

    return 0;
}

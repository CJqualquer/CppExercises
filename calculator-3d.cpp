#include <iostream>
#include <cmath>

// Function declarations
void displayMenu(int & choice);
void switchCase(int choice);
void printArtcube();
void printArtsphere();
void printArtcylinder();
void printArtcone();
void printArtprism();

// ------------------------------------------------------------

class geometricShape {
   public: double side;
   double radius;
   double height;
   double baseArea;
};
class cube: public geometricShape {
   public:

      double calculateVolume() {
         return pow(side, 3);
      }

   double calculateArea() {
      return pow(side, 2) * 6;
   }
};
class sphere: public geometricShape {
   public:

      double calculateArea() {
         return 4 * M_PI * std::pow(radius, 2);
      }

   double calculateVolume() {
      return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
   }
};
class cylinder: public geometricShape {
   public:

      double calculateArea() {
         return 2 * M_PI * radius * (radius + height);
      }

   double calculateVolume() {
      return M_PI * std::pow(radius, 2) * height;
   }
};
class cone: public geometricShape {
   public:

      double calculateArea() {
         double slantHeight = std::sqrt(std::pow(radius, 2) + std::pow(height, 2));
         return M_PI * radius * (radius + slantHeight);
      }

   double calculateVolume() {
      return (1.0 / 3.0) * M_PI * std::pow(radius, 2) * height;
   }
};
class prism: public geometricShape {
   public:

      double calculateArea() {
         return 2 * baseArea + perimeter() * height;
      }

   double calculateVolume() {
      return baseArea * height;
   }

   private: double perimeter() {
      return 0.0;
   }
};

// ------------------------------------------------------------

int main() {
   std::cout << "*********Calculator-3D*********\n";

   int choice;
   displayMenu(choice);
   switchCase(choice);

   std::cout << "*******************************\n";

   return 0;
}

// ------------------------------------------------------------

void displayMenu(int & choice) {
   std::cout << "3D Geometric Shape Calculator\n";
   std::cout << "1. Cube\n";
   std::cout << "2. Sphere\n";
   std::cout << "3. Cylinder\n";
   std::cout << "4. Cone\n";
   std::cout << "5. Prism\n";
   std::cout << "Select a shape to calculate area and volume: ";
   std::cin >> choice;
}

// ------------------------------------------------------------

void switchCase(int choice) {
   switch (choice) {
   case 1:
      cube c;
         std::cout << "Enter the length of the cube's side: ";
         std::cin >> c.side;
         printArtcube();
         std::cout << "Area: " << c.calculateArea() << "\n";
         std::cout << "Volume: " << c.calculateVolume() << "\n";
         break;
   case 2:
      sphere s;
      std::cout << "Enter the radius of the sphere: ";
      std::cin >> s.radius;
      printArtsphere();
      std::cout << "Area: " << s.calculateArea() << "\n";
      std::cout << "Volume: " << s.calculateVolume() << "\n";
      break;
   case 3:
      cylinder cyl;
      std::cout << "Enter the radius of the cylinder: ";
      std::cin >> cyl.radius;
      std::cout << "Enter the height of the cylinder: ";
      std::cin >> cyl.height;
      printArtcylinder();
      std::cout << "Area: " << cyl.calculateArea() << "\n";
      std::cout << "Volume: " << cyl.calculateVolume() << "\n";
      break;
   case 4:
      cone con;
      std::cout << "Enter the radius of the cone: ";
      std::cin >> con.radius;
      std::cout << "Enter the height of the cone: ";
      std::cin >> con.height;
      printArtcone();
      std::cout << "Area: " << con.calculateArea() << "\n";
      std::cout << "Volume: " << con.calculateVolume() << "\n";
      break;
   case 5:
      prism p;
      std::cout << "Enter the base area of the prism: ";
      std::cin >> p.baseArea;
      std::cout << "Enter the height of the prism: ";
      std::cin >> p.height;
      printArtprism();
      std::cout << "Area: " << p.calculateArea() << "\n";
      std::cout << "Volume: " << p.calculateVolume() << "\n";
      break;
   default:
      break;
   }
}

// ------------------------------------------------------------

void printArtcube() {
   std::cout << "     +------+  \n";
   std::cout << "    /      /|  \n";
   std::cout << "   +------+ |  \n";
   std::cout << "   |      | +  \n";
   std::cout << "   |      |/   \n";
   std::cout << "   +------+    \n";
}
void printArtsphere() {
   std::cout << "     ***     \n";
   std::cout << "   *     *   \n";
   std::cout << "   *     *   \n";
   std::cout << "     ***     \n";
}
void printArtcylinder() {
   std::cout << "    _____    \n";
   std::cout << "  /       \\  \n";
   std::cout << " |         | \n";
   std::cout << " |         | \n";
   std::cout << "  \\_______/  \n";
}
void printArtcone() {
   std::cout << "     /\\     \n";
   std::cout << "    /  \\    \n";
   std::cout << "   /    \\   \n";
   std::cout << "  /______\\  \n";
}
void printArtprism() {
   std::cout << "   /|\\    \n";
   std::cout << "  / | \\   \n";
   std::cout << " /  |  \\  \n";
   std::cout << "/___|___\\ \n";
}

// ------------------------------------------------------------
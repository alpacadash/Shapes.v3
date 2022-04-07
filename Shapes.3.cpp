#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Square
{
  double side;
  void calcSquare(ofstream&) const;
};

struct Rectangle
{
  double length;
  double width;
  void calcRectangle(ofstream&) const;
};

struct Circle
{
  double radius;
  void calcCircle(ofstream&) const;
};

struct Triangle
{
  double side;
  void calcTriangle(ofstream&) const;
};

struct Cube
{
  double side;
  void calcCube(ofstream&) const;
};

struct Box
{
  double length;
  double width;
  double height;
  void calcBox(ofstream&) const;
};

struct Cylinder
{
  double radius;
  double height;
  void calcCylinder(ofstream&) const;
};

struct Prism
{
  double side;
  double height;
  void calcPrism(ofstream&) const;
};

ostream& roundingTwo(ostream&);
ostream& roundingOff(ostream&);
Square tokensToSquare(vector<string>&);
Rectangle tokensToRectangle(vector<string>&);
Circle tokensToCircle(vector<string>&);
Triangle tokensToTriangle(vector<string>&);
Cube tokensToCube(vector<string>&);
Box tokensToBox(vector<string>&);
Cylinder tokensToCylinder(vector<string>&);
Prism tokensToPrism(vector<string>&);
vector<string> parseString(string);
vector<void*> bag(ifstream&, ofstream&, vector<int>&);
void deleteBag(vector<void*>&, vector<int>&);
void readBag(ofstream&, vector<void*>&, vector<int>&);

int main()
{
  cout << "Programmer: Younghyun Kwon\n";
  cout << "Programmer's ID: 1651849\n";
  ifstream fin;
  ofstream fout;
  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");
  vector<int> bagsType;
  vector<void*> bags = bag(fin,fout,bagsType);

  readBag(fout,bags,bagsType);
  deleteBag(bags,bagsType);
  fin.close();
  fout.close();
}

void Square::calcSquare(ofstream& out) const
{
  double side = this->side;
  double area = side*side;
  double perimeter = side*4;
  cout << "SQUARE side=" << side;
  out << "SQUARE side=" << side;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Rectangle::calcRectangle(ofstream& out) const
{
  double length = this->length;
  double width = this->width;
  double area = length*width;
  double perimeter = length*2 + width*2;
  cout << "RECTANGLE length=" << length << " width=" << width;
  out << "RECTANGLE length=" << length << " width=" << width;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Circle::calcCircle(ofstream& out) const
{
  double radius = this->radius;
  double area = M_PI*radius*radius;
  double perimeter = 2*M_PI*radius;
  cout << "CIRCLE radius=" << radius;
  out << "CIRCLE radius=" << radius;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Triangle::calcTriangle(ofstream& out) const
{
  double side = this->side;
  double area = (sqrt(3)*side*side)/4;
  double perimeter = 3*side;
  cout << "TRIANGLE side=" << side;
  out << "TRIANGLE side=" << side;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Cube::calcCube(ofstream& out) const
{
  double side = this->side;
  double area = side*side*6;
  double volume = side*side*side;
  cout << "CUBE side=" << side;
  out << "CUBE side=" << side;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Box::calcBox(ofstream& out) const
{
  double length = this->length;
  double width = this->width;
  double height = this->height;
  double area = length*width*2 + width*height*2 + length*height*2;
  double volume = length*width*height;
  cout << "BOX side=" << length << " width=" << width << " height=" << height;
  out << "BOX side=" << length << " width=" << width << " height=" << height;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Cylinder::calcCylinder(ofstream& out) const
{
  double radius = this->radius;
  double height = this->height;
  double area = M_PI*radius*radius*2 + height*2*M_PI*radius;
  double volume = M_PI*radius*radius*height;
  cout << "CYLINDER radius=" << radius << " height=" << height;
  out << "CYLINDER radius=" << radius << " height=" << height;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Prism::calcPrism(ofstream& out) const
{
  double side = this->side;
  double height = this->height;
  double area = (sqrt(3)*side*side*2)/4 + 3*side*height;
  double volume = (sqrt(3)*side*side*height)/4;
  cout << "PRISM side=" << side << " height=" << height;
  out << "PRISM side=" << side << " height=" << height;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

ostream& roundingTwo(ostream& out)
  {
    out.setf(ios::fixed);
    out.precision(2);
    return out;
  }

  ostream& roundingOff(ostream& out)
  {
    out.unsetf(ios::fixed);
    out.precision(6);
    return out;
  }

Square tokensToSquare(vector<string>& token)
{
  Square* square = new Square;
  square->side = (token.size() == 1)? 0 : atof(token[1].c_str());
  Square& rSquare = *square;
  return rSquare;
}

Rectangle tokensToRectangle(vector<string>& token)
{
  Rectangle* rectangle = new Rectangle;
  rectangle->length = (token.size() == 1)? 0 : atof(token[1].c_str());
  rectangle->width = (token.size() >= 3)? atof(token[2].c_str()) : 0;
  Rectangle& rRectangle = *rectangle;
  return rRectangle;
}

Circle tokensToCircle(vector<string>& token)
{
  Circle* circle = new Circle;
  circle->radius = (token.size() == 1)? 0 : atof(token[1].c_str());
  Circle& rCircle = *circle;
  return rCircle;
}

Triangle tokensToTriangle(vector<string>& token)
{
  Triangle* triangle = new Triangle;
  triangle->side = (token.size() == 1)? 0 : atof(token[1].c_str());
  Triangle& rTriangle = *triangle;
  return rTriangle;
}

Cube tokensToCube(vector<string>& token)
{
  Cube* cube = new Cube;
  cube->side = (token.size() == 1)? 0 : atof(token[1].c_str());
  Cube& rCube = *cube;
  return rCube;
}

Box tokensToBox(vector<string>& token)
{
  Box* box = new Box;
  box->length = (token.size() == 1)? 0 : atof(token[1].c_str());
  box->width = (token.size() >= 3)? atof(token[2].c_str()) : 0;
  box->height = (token.size() >= 4)? atof(token[3].c_str()) : 0;
  Box& rBox = *box;
  return rBox;
}

Cylinder tokensToCylinder(vector<string>& token)
{
  Cylinder* cylinder = new Cylinder;
  cylinder->radius = (token.size() == 1)? 0 : atof(token[1].c_str());
  cylinder->height = (token.size() >= 3)? atof(token[2].c_str()) : 0;
  Cylinder& rCylinder = *cylinder;
  return rCylinder;
}

Prism tokensToPrism(vector<string>& token)
{
  Prism* prism = new Prism;
  prism->side = (token.size() == 1)? 0 : atof(token[1].c_str());
  prism->height = (token.size() >= 3)? atof(token[2].c_str()) : 0;
  Prism& rPrism = *prism;
  return rPrism;
}

vector<string> parseString(string str)
{
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

vector<void*> bag(ifstream& in, ofstream& out, vector<int>& bagType)
{
  string shape;
  vector<string> tokens;
  vector<void*> myBag;
  while(!in.eof())
  {
    getline(in,shape);
    if(shape.find_first_not_of(" ") != string::npos)
    {
      tokens = parseString(shape);
      if(tokens[0] == "SQUARE")
      {
        Square* square = new Square;
        *square = tokensToSquare(tokens);
        myBag.push_back(square);
        bagType.push_back(1);
      }
      else if(tokens[0] == "RECTANGLE")
      {
        Rectangle* rectangle = new Rectangle;
        *rectangle = tokensToRectangle(tokens);
        myBag.push_back(rectangle);
        bagType.push_back(2);
      }
      else if(tokens[0] == "CIRCLE")
      {
        Circle* circle = new Circle;
        *circle = tokensToCircle(tokens);
        myBag.push_back(circle);
        bagType.push_back(3);
      }
      else if(tokens[0] == "TRIANGLE")
      {
        Triangle* triangle = new Triangle;
        *triangle = tokensToTriangle(tokens);
        myBag.push_back(triangle);
        bagType.push_back(4);
      }
      else if(tokens[0] == "CUBE")
      {
        Cube* cube = new Cube;
        *cube = tokensToCube(tokens);
        myBag.push_back(cube);
        bagType.push_back(5);
      }
      else if(tokens[0] == "BOX")
      {
        Box* box = new Box;
        *box = tokensToBox(tokens);
        myBag.push_back(box);
        bagType.push_back(6);
      }
      else if(tokens[0] == "CYLINDER")
      {
        Cylinder* cylinder = new Cylinder;
        *cylinder = tokensToCylinder(tokens);
        myBag.push_back(cylinder);
        bagType.push_back(7);
      }
      else if(tokens[0] == "PRISM")
      {
        Prism* prism = new Prism;
        *prism = tokensToPrism(tokens);
        myBag.push_back(prism);
        bagType.push_back(8);
      }
      else if(shape.compare("EOF") == 0) break;
      else{ cout << tokens[0] << " invalid object" << endl; }
    }
  }
  return myBag;
}


void deleteBag(vector<void*>& myBag, vector<int>& myBagType)
{
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 1)
    {
      Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
      delete pSquare;
    }
    else if(myBagType[i] == 2)
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
      delete pRectangle;
    }
    else if(myBagType[i] == 3)
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
      delete pCircle;
    }
    else if(myBagType[i] == 4)
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
      delete pTriangle;
    }
    else if(myBagType[i] == 5)
    {
      {
        Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
        delete pCube;
      }
    }
    else if(myBagType[i] == 6)
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[i]);
      delete pBox;
    }
    else if(myBagType[i] == 7)
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
      delete pCylinder;
    }
    else if(myBagType[i] == 8)
    {
      Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
      delete pPrism;
    }
  }
}

void readBag(ofstream& out, vector<void*>& myBag, vector<int>& myBagType)
{
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 1)
    {
      Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
      Square& rSquare = *pSquare;
      rSquare.calcSquare(out);
    }
    else if(myBagType[i] == 2)
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
      Rectangle& rRectangle = *pRectangle;
      rRectangle.calcRectangle(out);
    }
    else if(myBagType[i] == 3)
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
      Circle& rCircle = *pCircle;
      rCircle.calcCircle(out);
    }
    else if(myBagType[i] == 4)
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
      Triangle& rTriangle = *pTriangle;
      rTriangle.calcTriangle(out);
    }
    else if(myBagType[i] == 5)
    {
      {
        Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
        Cube& rCube = *pCube;
        rCube.calcCube(out);
      }
    }
    else if(myBagType[i] == 6)
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[i]);
      Box& rBox = *pBox;
      rBox.calcBox(out);
    }
    else if(myBagType[i] == 7)
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
      Cylinder& rCylinder = *pCylinder;
      rCylinder.calcCylinder(out);
    }
    else if(myBagType[i] == 8)
    {
      Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
      Prism& rPrism = *pPrism;
      rPrism.calcPrism(out);
    }
  }
}

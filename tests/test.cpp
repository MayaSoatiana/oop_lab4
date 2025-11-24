#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include "figure.h"
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"
#include "dynamicArray.h"

// Test fixture for common setup
class FigureTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Pentagon points
        pentagonPoints.add(Point<double>(1, 1));
        pentagonPoints.add(Point<double>(4, 2));
        pentagonPoints.add(Point<double>(3, 5));
        pentagonPoints.add(Point<double>(0, 4));
        pentagonPoints.add(Point<double>(-1, 2));

        // Hexagon points
        hexagonPoints.add(Point<double>(0, 0));
        hexagonPoints.add(Point<double>(2, 0));
        hexagonPoints.add(Point<double>(3, 1));
        hexagonPoints.add(Point<double>(2, 2));
        hexagonPoints.add(Point<double>(0, 2));
        hexagonPoints.add(Point<double>(-1, 1));

        // Octagon points
        octagonPoints.add(Point<double>(0, 0));
        octagonPoints.add(Point<double>(2, 0));
        octagonPoints.add(Point<double>(3, 1));
        octagonPoints.add(Point<double>(3, 3));
        octagonPoints.add(Point<double>(2, 4));
        octagonPoints.add(Point<double>(0, 4));
        octagonPoints.add(Point<double>(-1, 3));
        octagonPoints.add(Point<double>(-1, 1));
    }

    DynamicArray<Point<double>> pentagonPoints;
    DynamicArray<Point<double>> hexagonPoints;
    DynamicArray<Point<double>> octagonPoints;
};

// Test constructors
TEST_F(FigureTest, PentagonConstructor) {
    EXPECT_NO_THROW(Pentagon<double> pentagon(pentagonPoints));
    
    DynamicArray<Point<double>> invalidPoints;
    invalidPoints.add(Point<double>(0, 0));
    EXPECT_THROW(Pentagon<double> invalidPentagon(invalidPoints), std::invalid_argument);
}

TEST_F(FigureTest, HexagonConstructor) {
    EXPECT_NO_THROW(Hexagon<double> hexagon(hexagonPoints));
    
    DynamicArray<Point<double>> invalidPoints;
    invalidPoints.add(Point<double>(0, 0));
    EXPECT_THROW(Hexagon<double> invalidHexagon(invalidPoints), std::invalid_argument);
}

TEST_F(FigureTest, OctagonConstructor) {
    EXPECT_NO_THROW(Octagon<double> octagon(octagonPoints));
    
    DynamicArray<Point<double>> invalidPoints;
    invalidPoints.add(Point<double>(0, 0));
    EXPECT_THROW(Octagon<double> invalidOctagon(invalidPoints), std::invalid_argument);
}

// Test geometric center calculations
TEST_F(FigureTest, PentagonGeometricCenter) {
    Pentagon<double> pentagon(pentagonPoints);
    Point<double> center = pentagon.geometric_center();
    EXPECT_DOUBLE_EQ(center.get_x(), 1.4);
    EXPECT_DOUBLE_EQ(center.get_y(), 2.8);
}

TEST_F(FigureTest, HexagonGeometricCenter) {
    Hexagon<double> hexagon(hexagonPoints);
    Point<double> center = hexagon.geometric_center();
    EXPECT_DOUBLE_EQ(center.get_x(), 1.0);
    EXPECT_DOUBLE_EQ(center.get_y(), 1.0);
}

TEST_F(FigureTest, OctagonGeometricCenter) {
    Octagon<double> octagon(octagonPoints);
    Point<double> center = octagon.geometric_center();
    EXPECT_DOUBLE_EQ(center.get_x(), 1.0);
    EXPECT_DOUBLE_EQ(center.get_y(), 2.0);
}

// Test area calculations
TEST_F(FigureTest, PentagonArea) {
    Pentagon<double> pentagon(pentagonPoints);
    double area = static_cast<double>(pentagon);
    EXPECT_DOUBLE_EQ(area, 12.5);
}

TEST_F(FigureTest, HexagonArea) {
    Hexagon<double> hexagon(hexagonPoints);
    double area = static_cast<double>(hexagon);
    EXPECT_DOUBLE_EQ(area, 6.0);
}

TEST_F(FigureTest, OctagonArea) {
    Octagon<double> octagon(octagonPoints);
    double area = static_cast<double>(octagon);
    EXPECT_DOUBLE_EQ(area, 14.0);
}

// Test print vertices
TEST_F(FigureTest, PentagonPrintVertices) {
    Pentagon<double> pentagon(pentagonPoints);
    std::stringstream ss;
    pentagon.print_vertices(ss);
    std::string output = ss.str();
    EXPECT_FALSE(output.empty());
}

TEST_F(FigureTest, HexagonPrintVertices) {
    Hexagon<double> hexagon(hexagonPoints);
    std::stringstream ss;
    hexagon.print_vertices(ss);
    std::string output = ss.str();
    EXPECT_FALSE(output.empty());
}

TEST_F(FigureTest, OctagonPrintVertices) {
    Octagon<double> octagon(octagonPoints);
    std::stringstream ss;
    octagon.print_vertices(ss);
    std::string output = ss.str();
    EXPECT_FALSE(output.empty());
}

// Test read vertices
TEST_F(FigureTest, PentagonReadVertices) {
    Pentagon<double> pentagon;
    std::stringstream ss("1 1 4 2 3 5 0 4 -1 2");
    EXPECT_NO_THROW(pentagon.read_vertices(ss));
    
    Point<double> center = pentagon.geometric_center();
    EXPECT_DOUBLE_EQ(center.get_x(), 1.4);
    EXPECT_DOUBLE_EQ(center.get_y(), 2.8);
}

TEST_F(FigureTest, HexagonReadVertices) {
    Hexagon<double> hexagon;
    std::stringstream ss("0 0 2 0 3 1 2 2 0 2 -1 1");
    EXPECT_NO_THROW(hexagon.read_vertices(ss));
    
    Point<double> center = hexagon.geometric_center();
    EXPECT_DOUBLE_EQ(center.get_x(), 1.0);
    EXPECT_DOUBLE_EQ(center.get_y(), 1.0);
}

TEST_F(FigureTest, OctagonReadVertices) {
    Octagon<double> octagon;
    std::stringstream ss("0 0 2 0 3 1 3 3 2 4 0 4 -1 3 -1 1");
    EXPECT_NO_THROW(octagon.read_vertices(ss));
    
    Point<double> center = octagon.geometric_center();
    EXPECT_DOUBLE_EQ(center.get_x(), 1.0);
    EXPECT_DOUBLE_EQ(center.get_y(), 2.0);
}

// Test assignment operators
TEST_F(FigureTest, PentagonAssignment) {
    Pentagon<double> pentagon1(pentagonPoints);
    Pentagon<double> pentagon2;
    
    pentagon2 = pentagon1;
    Point<double> center1 = pentagon1.geometric_center();
    Point<double> center2 = pentagon2.geometric_center();
    
    EXPECT_DOUBLE_EQ(center1.get_x(), center2.get_x());
    EXPECT_DOUBLE_EQ(center1.get_y(), center2.get_y());
    
    // Test move assignment
    Pentagon<double> pentagon3;
    pentagon3 = std::move(pentagon1);
    Point<double> center3 = pentagon3.geometric_center();
    EXPECT_DOUBLE_EQ(center3.get_x(), 1.4);
    EXPECT_DOUBLE_EQ(center3.get_y(), 2.8);
}

TEST_F(FigureTest, HexagonAssignment) {
    Hexagon<double> hexagon1(hexagonPoints);
    Hexagon<double> hexagon2;
    
    hexagon2 = hexagon1;
    Point<double> center1 = hexagon1.geometric_center();
    Point<double> center2 = hexagon2.geometric_center();
    
    EXPECT_DOUBLE_EQ(center1.get_x(), center2.get_x());
    EXPECT_DOUBLE_EQ(center1.get_y(), center2.get_y());
    
    // Test move assignment
    Hexagon<double> hexagon3;
    hexagon3 = std::move(hexagon1);
    Point<double> center3 = hexagon3.geometric_center();
    EXPECT_DOUBLE_EQ(center3.get_x(), 1.0);
    EXPECT_DOUBLE_EQ(center3.get_y(), 1.0);
}

TEST_F(FigureTest, OctagonAssignment) {
    Octagon<double> octagon1(octagonPoints);
    Octagon<double> octagon2;
    
    octagon2 = octagon1;
    Point<double> center1 = octagon1.geometric_center();
    Point<double> center2 = octagon2.geometric_center();
    
    EXPECT_DOUBLE_EQ(center1.get_x(), center2.get_x());
    EXPECT_DOUBLE_EQ(center1.get_y(), center2.get_y());
    
    // Test move assignment
    Octagon<double> octagon3;
    octagon3 = std::move(octagon1);
    Point<double> center3 = octagon3.geometric_center();
    EXPECT_DOUBLE_EQ(center3.get_x(), 1.0);
    EXPECT_DOUBLE_EQ(center3.get_y(), 2.0);
}

// Test DynamicArray functionality
TEST(DynamicArrayTest, BasicOperations) {
    DynamicArray<Figure<double>*> figures;
    
    DynamicArray<Point<double>> pentagonPoints;
    pentagonPoints.add(Point<double>(0, 0));
    pentagonPoints.add(Point<double>(1, 0));
    pentagonPoints.add(Point<double>(1, 1));
    pentagonPoints.add(Point<double>(0, 1));
    pentagonPoints.add(Point<double>(0.5, 2));
    
    Pentagon<double>* pentagon = new Pentagon<double>(pentagonPoints);
    figures.add(pentagon);
    
    EXPECT_EQ(figures.getSize(), 1);
    EXPECT_DOUBLE_EQ(figures.TotalArea(), static_cast<double>(*pentagon));
    
    figures.DeleteFigure(0);
    EXPECT_EQ(figures.getSize(), 0);
}

TEST(DynamicArrayTest, TotalAreaCalculation) {
    DynamicArray<Figure<double>*> figures;
    
    // Create pentagon
    DynamicArray<Point<double>> pentagonPoints;
    pentagonPoints.add(Point<double>(1, 1));
    pentagonPoints.add(Point<double>(4, 2));
    pentagonPoints.add(Point<double>(3, 5));
    pentagonPoints.add(Point<double>(0, 4));
    pentagonPoints.add(Point<double>(-1, 2));
    figures.add(new Pentagon<double>(pentagonPoints));
    
    // Create hexagon
    DynamicArray<Point<double>> hexagonPoints;
    hexagonPoints.add(Point<double>(0, 0));
    hexagonPoints.add(Point<double>(2, 0));
    hexagonPoints.add(Point<double>(3, 1));
    hexagonPoints.add(Point<double>(2, 2));
    hexagonPoints.add(Point<double>(0, 2));
    hexagonPoints.add(Point<double>(-1, 1));
    figures.add(new Hexagon<double>(hexagonPoints));
    
    // Create octagon
    DynamicArray<Point<double>> octagonPoints;
    octagonPoints.add(Point<double>(0, 0));
    octagonPoints.add(Point<double>(2, 0));
    octagonPoints.add(Point<double>(3, 1));
    octagonPoints.add(Point<double>(3, 3));
    octagonPoints.add(Point<double>(2, 4));
    octagonPoints.add(Point<double>(0, 4));
    octagonPoints.add(Point<double>(-1, 3));
    octagonPoints.add(Point<double>(-1, 1));
    figures.add(new Octagon<double>(octagonPoints));
    
    double totalArea = figures.TotalArea();
    EXPECT_DOUBLE_EQ(totalArea, 32.5); // 12.5 + 6 + 14
    
    // Cleanup
    for (size_t i = 0; i < figures.getSize(); ++i) {
        delete figures[i];
    }
}

TEST(DynamicArrayTest, PrintFigures) {
    DynamicArray<Figure<double>*> figures;
    
    DynamicArray<Point<double>> pentagonPoints;
    pentagonPoints.add(Point<double>(0, 0));
    pentagonPoints.add(Point<double>(1, 0));
    pentagonPoints.add(Point<double>(1, 1));
    pentagonPoints.add(Point<double>(0, 1));
    pentagonPoints.add(Point<double>(0.5, 2));
    
    figures.add(new Pentagon<double>(pentagonPoints));
    
    std::stringstream ss;
    testing::internal::CaptureStdout();
    figures.PrintFigures();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_FALSE(output.empty());
    
    // Cleanup
    for (size_t i = 0; i < figures.getSize(); ++i) {
        delete figures[i];
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
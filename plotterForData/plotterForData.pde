ArrayList<ArrayList<Float>> DataArray = new ArrayList<ArrayList<Float>>();
float Xdensity = 0;
float Ydensity = 0;
float Xjump    = 0.0;
float Yjump    = 0.0;

float Xspacing = 0.0;
float Yspacing = 0.0;

void setup()
{
    size(800,800);

    loadData();
    printParameters();

    background(30,30,30);
    displayData();
}
void draw(){}


void loadData()
{
    /*
    Loads density and jump data, as well as all data points into the 2D array
    */
    String[] DataLines = loadStrings("DataFile.txt");
    //Read spec
    ArrayList<Float> specification = SeparateValues(DataLines[0]);
    Xdensity = specification.get(0);
    Ydensity = specification.get(1);
    Xjump    = specification.get(2);
    Yjump    = specification.get(3);
    Xspacing =  width/Xdensity;
    Yspacing = height/Ydensity;
    //Read data
    for(int p=1; p<DataLines.length; p++)
    {
        ArrayList<Float> dataValues = SeparateValues(DataLines[p]);
        DataArray.add(new ArrayList<Float>());
        for(int q=0; q<dataValues.size(); q++)
        {
            DataArray.get(p-1).add(dataValues.get(q));
        }
    }
}
void printParameters()
{
    println("Xdensity -> ",Xdensity);
    println("Ydensity -> ",Ydensity);
    println("Xjump    -> ",Xjump);
    println("Xjump    -> ",Yjump);
    println("Xspacing -> ",Xspacing);
    println("Yspacing -> ",Yspacing);
}
void displayData()
{
    pushStyle();
    for(int j=0; j<DataArray.size(); j++)
    {
        for(int i=0; i<DataArray.get(j).size(); i++)
        {
            PVector colour = GetColour(DataArray.get(j).get(i));
            fill(colour.x, colour.y, colour.z);
            noStroke();
            ellipse(i*Xspacing, j*Yspacing, 0.75*Xspacing, 0.75*Yspacing);
        }
    }
    popStyle();
}
PVector GetColour(float value)
{
    float valueMax = 60.0;  //Effects limitting values for different colouration; NOT STRICTLY THE MAX VALUE, JUST USED TO CREATE DESIRED COLOUR EFFECT WITH RATIO
    float ratio    = value/valueMax;
    PVector colour = new PVector(255*ratio,155,155);
    return colour;
}
ArrayList<Float> SeparateValues(String line)
{
    /*
    Takes a line, reads from the start up to the next comma
    Returns a list of elements from the line split at the commas, all cast to floats
    */
    ArrayList<Float> valueSet = new ArrayList<Float>();
    String number = "";
    for(int i=0; i<line.length(); i++)
    {
        char givenChar = line.charAt(i);
        boolean atComma = givenChar == ','; //All end in commas, so dont need to check for end of line too
        if(atComma)
        {
            valueSet.add(float(number));
            number = "";
        }
        else
        {
            number = number + givenChar;
        }
    }
    return valueSet;
}
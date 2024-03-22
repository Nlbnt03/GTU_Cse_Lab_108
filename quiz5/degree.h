void celsius_to_fah_kel(double celsius, double *fahrenheit, double *kelvin)
{
    *fahrenheit = ((celsius * 9) / 5) + 32;
    *kelvin = celsius + 273.15; 
}

void fahrenheit_to_cel_kel(double fahrenheit, double *celsius, double *kelvin)
{
    *celsius = ((fahrenheit - 32) / 9) * 5;
    *kelvin = (((fahrenheit - 32) / 9) * 5) + 273.15;
}

void kelvin_to_cel_fah(double kelvin, double *celsius, double *fahrenheit)
{
    *celsius = kelvin - 273.15;
    *fahrenheit = (((kelvin - 273.15) * 9) / 5) + 32;
}


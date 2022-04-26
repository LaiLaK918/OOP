using namespace std;
string factorial(int factorial)
{
  string res;

  string pres;

  string tres;

  string cres;

  int max = 1000000;

  for (int I = 0; I <= max; I++)
  {
    pres.push_back(47);
    tres.push_back(47);
    cres.push_back(47);

    if (I == max)
    {
      pres[I] = 49;
      tres[I] = 49;
      cres[I] = 49;
    }
  }


  int num1 = 0;
  int num2 = 0;
  int right_max = 0;
  int dec = 0;

  for (int i = 2; i <= factorial; i++)
  {
    for (int j = max; j >= 0; j--)
    {
      if (pres[j] == 47)
      {
        right_max = j;
        break;
      }
    }
    dec = i;

    if (dec % 10 == 0)
    {
      while (dec % 10 == 0)
      {
        for (int k = right_max - 3; k <= max; k++)
        {
          pres[k - 1] = pres[k];
        }
        pres[max] = 48;
        dec = dec / 10;
      }
      for (int j = max; j >= 0; j--)
      {
        if (pres[j] == 47)
        {
          right_max = j;
          break;
        }
      }
    }
    if (dec != 1)
    {
      if (dec < 10)
      {
        num2 = 0;
        for (int k = max; k > right_max; k--)
        {
          if (pres[k] != 47)
          {
            num1 = (pres[k] - 48) * dec + num2;
            if (num1 >= 10)
            {
              pres[k] = (num1 % 10) + 48;
              num2 = num1 / 10;
            }
            else if (num1 < 10)
            {
              pres[k] = num1 + 48;
              num2 = 0;
            }
            if (pres[k - 1] == 47 && num2 > 0)
            {
              pres[k - 1] = num2 + 48;
            }
          }
        }
      }
      if (dec > 10)
      {
        tres = pres;
        num2 = 0;
        for (int k = max; k > right_max; k--)
        {
          if (tres[k] != 47)
          {
            num1 = (tres[k] - 48) * (dec % 10) + num2;
            if (num1 >= 10)
            {
              tres[k] = (num1 % 10) + 48;
              num2 = num1 / 10;
            }
            else if (num1 < 10)
            {
              tres[k] = num1 + 48;
              num2 = 0;
            }

            if (tres[k - 1] == 47 && num2 > 0)
            {
              tres[k - 1] = num2 + 48;
            }
          }
        }
        while (dec > 10)
        {
          for (int k = right_max - 12; k <= max; k++)
          {
            pres[k - 1] = pres[k];
          }
          pres[max] = 48;
          right_max--;

          cres = pres;

          dec = dec / 10;
          if (dec % 10 == 0)
          {
            while (dec % 10 == 0)
            {
              for (int k = right_max - 12; k <= max; k++)
              {
                cres[k - 1] = cres[k];
              }
              cres[max] = 48;
              dec = dec / 10;
            }

            for (int j = max; j >= 0; j--)
            {
              if (pres[j] == 47)
              {
                right_max = j;
                break;
              }
            }

            pres = cres;
            num2 = 0;
            for (int k = max; k > right_max - 2; k--)
            {
              if (cres[k] != 47)
              {
                num1 = (cres[k] - 48) * (dec % 10) + num2;
                if (num1 >= 10)
                {
                  cres[k] = (num1 % 10) + 48;
                  num2 = num1 / 10;
                }
                else if (num1 < 10)
                {
                  cres[k] = num1 + 48;
                  num2 = 0;
                }
                if (cres[k - 1] == 47 && num2 > 0)//// обнулить нам и нам2
                {
                  cres[k - 1] = num2 + 48;
                  num2 = 0;
                  break;
                }
              }
            }
            for (int j = max; j >= 0; j--)
            {
              if (pres[j] == 47)
              {
                right_max = j;
                break;
              }
            }
          }
          else
          {
            num2 = 0;
            for (int k = max; k > right_max; k--)
            {
              if (cres[k] != 47)
              {
                num1 = (cres[k] - 48) * (dec % 10) + num2;
                if (num1 >= 10)
                {
                  cres[k] = (num1 % 10) + 48;
                  num2 = num1 / 10;
                }
                else if (num1 < 10)
                {
                  cres[k] = num1 + 48;
                  num2 = 0;
                }
                if (cres[k - 1] == 47 && num2 > 0)
                {
                  cres[k - 1] = num2 + 48;
                  num2 = 0;
                  break;
                }
              }
            }

            for (int j = max; j >= 0; j--)
            {
              if (cres[j] == 47)
              {
                right_max = j;
                break;
              }
            }
          }
          if (i == factorial)
          {
            cout << endl << endl << endl;
            cout << "pres: " << endl;
            for (int i = 0; i <= max; i++)
            {
              if (pres[i] != 47)
              {
                cout << pres[i];
              }
            }
            cout << endl << endl << endl;
            cout << "tres: " << endl;
            for (int i = 0; i <= max; i++)
            {
              if (tres[i] != 47)
              {
                cout << tres[i];
              }
            }
            cout << endl << endl << endl;
            cout << "cres: " << endl;
            for (int i = 0; i <= max; i++)
            {
              if (cres[i] != 47)
              {
                cout << cres[i];
              }
            }
            cout << endl << endl << endl;
          }


          num2 = 0;
          for (int k = max; k > right_max - 10; k--)
          {
            if (cres[k] > 47 && cres[k] < 58)
            {
              if (tres[k] < 48)
              {
                tres[k] = 48;
              }
              num1 = (cres[k] - 48) + (tres[k] - 48) + num2;

              if (num1 >= 10)
              {
                tres[k] = (num1 % 10) + 48;
                num2 = num1 / 10;
              }
              else if (num1 < 10)
              {
                tres[k] = num1 + 48;
                num2 = 0;
              }
              if ((cres[k - 1] < 48 && num2 > 0) || (cres[k - 1] > 58 && num2 > 0))
              {
                tres[k - 1] = num2 + 48;
              }
            }
          }
        }
        pres = tres;
      }
    }
  }

  cres.clear();
  tres.clear();




  for (int i = 0; i < max + 1; i++)
  {
    if (pres[i] != 47)
    {
      res.push_back(pres[i]);
    }
  }
  
    pres.clear();
    
    
  return res;
}

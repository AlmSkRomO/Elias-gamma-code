# Elias gamma code
how does a decoder work:

  0. 1 char = 8 bit
  1. Separates the first bit (first bit = first boolean in sequence)
  2. Program find gamma groups (do not read the first bit)
  3. Translate gamma groups from 2 base to 10 base 
  4. Translate to series (5 - 11111)
  5. Initial value n = 128, multiply n by the bit on which the counter is located, then divide n by 2 and so on until n becomes 0, repeat this to the end
  6. All integer values are stored in the array, then through the “for” we substitute the value to ascii (char(arr[i]))

how does a encoder work:

  0. 1 char = 8 bit
  1. Translate from 10 base to 2 base
  2. Translate from 2 base to RLE (We count the number of 1 or 0 in the series, repeating until they run out)
  3. Translate from RLE to Elias gamma code (we take a number from rleArr[i] and divide it until it becomes 0 from this we know the number of zeros in front of the number. Next, we translate the number from rleArr[i] into binary form and insert the translated number before the number of zeros that we learned, repeat with all the numbers from rleArr)

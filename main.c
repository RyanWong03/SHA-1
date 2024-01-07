#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *xor_bit_string(const char *string1, const char *string2)
{
    size_t string_length = strlen(string1);
    char *result = malloc(string_length + 1);
    for(int i = 0; i < string_length; i++) result[i] = (string1[i] == string2[i]) ? '0' : '1';
    result[string_length] = '\0';
    return result;
}

char *not_bit_string(const char *string)
{
    size_t string_length = strlen(string);
    char *result = malloc(string_length + 1);
    for(int i = 0; i < string_length; i++) result[i] = (string[i] == '0') ? '1': '0';
    result[string_length] = '\0';
    return result;
}

char *or_bit_string(const char *string1, const char *string2)
{
    size_t string_length = strlen(string1);
    printf("%zu\n", string_length);
    printf("string1: %s\n", string1);
    char *result = malloc(string_length + 1);
    for(int i = 0; i < string_length; i++) result[i] = (string1[i] == '1' || string2[i] == '1') ? '1' : '0';
    result[string_length] = '\0';
    printf("result: %s\n", result);
    return result;
}

char *and_bit_string(const char *string1, const char *string2)
{
    size_t string_length = strlen(string1);
    char *result = malloc(string_length + 1);
    for(int i = 0; i < string_length; i++) result[i] = (string1[i] == '1' && string2[i] == '1') ? '1' : '0';
    result[string_length] = '\0';
    return result;
}

char *circular_shift(const char *string, int n)
{
    //Left rotation
    char *result = malloc(33);
    char *left_half = malloc(n);
    char *right_half = malloc(32 - n);
    for(int i = 0; i < n; i++) left_half[i] = string[i];
    for(int i = n; i < 32; i++) right_half[i - 1] = string[i];
    memcpy(result, right_half, 32 - n);
    memcpy(result + (32 - n), left_half, n);
    result[32] = '\0';
    return result;
}

char *decimal_to_binary(unsigned int n)
{
    char *result = calloc(33, sizeof(char));
    for(int i = 31; i >= 0; i--) result[31 - i] = ((n >> i) & 1) ? '1' : '0';
    result[32] = '\0';
    return result;
}

//Implementation based off verilog implementation from CSE 341 PA3.
char *full_adder(char a, char b, int cin)
{
    char *ret = malloc(3);
    int new_a = a - '0';
    int new_b = b - '0';
    int w1 = new_a ^ new_b;
    int sum = w1 ^ cin;
    int w2 = cin & new_b;
    int w3 = cin & new_a;
    int w4 = new_a & new_b;
    int cout = w2 | w3 | w4;
    ret[0] = (char)(sum + '0');
    ret[1] = (char)(cout + '0');
    ret[2] = '\0';
    return ret;
}

//Implementation based off verilog implementation from CSE 341 PA3.
char *thirty_two_bit_adder(char *x, char *y, int cin)
{
    char *ret = malloc(33);
    char *f0 = full_adder(x[31], y[31], cin);
    char *f1 = full_adder(x[30], y[30], (int)(f0[1] - '0'));
    char *f2 = full_adder(x[29], y[29], (int)(f1[1] - '0'));
    char *f3 = full_adder(x[28], y[28], (int)(f2[1] - '0'));
    char *f4 = full_adder(x[27], y[27], (int)(f3[1] - '0'));
    char *f5 = full_adder(x[26], y[26], (int)(f4[1] - '0'));
    char *f6 = full_adder(x[25], y[25], (int)(f5[1] - '0'));
    char *f7 = full_adder(x[24], y[24], (int)(f6[1] - '0'));
    char *f8 = full_adder(x[23], y[23], (int)(f7[1] - '0'));
    char *f9 = full_adder(x[22], y[22], (int)(f8[1] - '0'));
    char *f10 = full_adder(x[21], y[21], (int)(f9[1] - '0'));
    char *f11 = full_adder(x[20], y[20], (int)(f10[1] - '0'));
    char *f12 = full_adder(x[19], y[19], (int)(f11[1] - '0'));
    char *f13 = full_adder(x[18], y[18], (int)(f12[1] - '0'));
    char *f14 = full_adder(x[17], y[17], (int)(f13[1] - '0'));
    char *f15 = full_adder(x[16], y[16], (int)(f14[1] - '0'));
    char *f16 = full_adder(x[15], y[15], (int)(f15[1] - '0'));
    char *f17 = full_adder(x[14], y[14], (int)(f16[1] - '0'));
    char *f18 = full_adder(x[13], y[13], (int)(f17[1] - '0'));
    char *f19 = full_adder(x[12], y[12], (int)(f18[1] - '0'));
    char *f20 = full_adder(x[11], y[11], (int)(f19[1] - '0'));
    char *f21 = full_adder(x[10], y[10], (int)(f20[1] - '0'));
    char *f22 = full_adder(x[9], y[9], (int)(f21[1] - '0'));
    char *f23 = full_adder(x[8], y[8], (int)(f22[1] - '0'));
    char *f24 = full_adder(x[7], y[7], (int)(f23[1] - '0'));
    char *f25 = full_adder(x[6], y[6], (int)(f24[1] - '0'));
    char *f26 = full_adder(x[5], y[5], (int)(f25[1] - '0'));
    char *f27 = full_adder(x[4], y[4], (int)(f26[1] - '0'));
    char *f28 = full_adder(x[3], y[3], (int)(f27[1] - '0'));
    char *f29 = full_adder(x[2], y[2], (int)(f28[1] - '0'));
    char *f30 = full_adder(x[1], y[1], (int)(f29[1] - '0'));
    char *f31 = full_adder(x[0], y[0], (int)(f30[1] - '0'));
    ret[0] = f31[0];
    ret[1] = f30[0];
    ret[2] = f29[0];
    ret[3] = f28[0];
    ret[4] = f27[0];
    ret[5] = f26[0];
    ret[6] = f25[0];
    ret[7] = f24[0];
    ret[8] = f23[0];
    ret[9] = f22[0];
    ret[10] = f21[0];
    ret[11] = f20[0];
    ret[12] = f19[0];
    ret[13] = f18[0];
    ret[14] = f17[0];
    ret[15] = f16[0];
    ret[16] = f15[0];
    ret[17] = f14[0];
    ret[18] = f13[0];
    ret[19] = f12[0];
    ret[20] = f11[0];
    ret[21] = f10[0];
    ret[22] = f9[0];
    ret[23] = f8[0];
    ret[24] = f7[0];
    ret[25] = f6[0];
    ret[26] = f5[0];
    ret[27] = f4[0];
    ret[28] = f3[0];
    ret[29] = f2[0];
    ret[30] = f1[0];
    ret[31] = f0[0];
    ret[32] = '\0';
    return ret;
}

/**
 * Overview of how SHA-1 works.
 * Step 1: Convert each character in the password to binary (via the ascii table).
 *
 * Step 2: Generate 5 random strings of hexadecimal characters {H0 - H4}. Each string is 32 bits long.
 *
 * Step 3: Concatenate the binary representations of the characters in the password,
 * and pad the string until it reaches a length of a multiple of 512.
 * The padding is done by first appending a '1',
 * then appending '0's until the string reaches a length that is 64 less than a multiple of 512 (448, 960, etc).
 * After this, get the length of the password in binary form,
 * and store that as a 64-bit integer (as characters) and pad the string with it.
 *  For example: if the password is "abc", the binary representation would be "011000010110001001100011".
 *  This string has a length of 24. 24 in binary is 01100. This would need to be sign extended to 64 bits,
 *  then appended to the 448 characters in the string.
 *
 * Step 4: The padded input, M, is divided up into 512-bit chunks,
 * and each chunk is divided into 16 32-bit words {W0 - W15}.
 *
 * Step 5: Iterate through the padded input 80 times.
 * For iterations 16 through 79, where 16 <= i <= 79, perform the following operation:
 * W(i) = S^1 (W(i - 3) xor W(i - 8) xor W(i - 14) xor W(i - 16))
 *
 * Note on circular shift S^n(X):
 *  S^n(X) on the word X by n bits, where n is an integer between 0 and 32
 *  is defined by (X << n) OR (X >> 32 - n). Right shift here is equal to sra in MIPS assembly.
 *  Example: S^1(W(i)) where W(i) = 10010 would produce 00100.
 *  Explanation:
 *      (10010 << 1) = 00100
 *      (10010 >> 32 - 1) = 10010 >> 31 = 00000
 *      00100 | 00000 = 00100
 *
 *  Step 6: A = H0, B = H1, C = H2, D = H3, E = H4
 *
 *  Step 7: Iterate another 80 times. For each iteration compute
 *  temp = S^5 * A + f(i; B, C, D) + E + W(i) + K(i) More info on the function f and K(i) down below.
 *  E = D, D = C, S = S^30 * B, B = A, A = temp
 *
 *  Step 8: H0 += A, H1 += B, H2 += C, H3 += D, H4 += E
 *
 *  Step 9: Need to construct the final 160 bit string.
 *  HH = S^128(H0) | S^96(H1) | S^64(H2) | S^32(H3) | H4
 *
 *  The final string can be represented in bits or hexadecimal.
 *
 *  'f' Functions:
 *  f(i; B, C, D) = (B & C) | ((~B) & D)        for 0 <= i <= 19
 *  f(i; B, C, D) = B xor C xor D               for 20 <= i <= 39
 *  f(i; B, C, D) = (B & C) | (B & D) | (C & D) for 40 <= i <= 59
 *  f(i; B, C, D) = B xor C xor D               for 60 <= i <= 79
 *
 *  K(i) values:
 *  K(i) = 0x5A827999   for 0 <= i <= 19
 *  K(i) = 0x63D9EBA1   for 20 <= i <= 39
 *  K(i) = 0x8F1BBCDC   for 40 <= i <= 59
 *  K(i) = 0xCA62C1D6   for 60 <= i <= 79
 * @param password
 * @return
 */

char *sha_1(char *password)
{
    size_t password_len = strlen(password);
    char *result = calloc(512 * password_len, sizeof(char));
    int result_index = 0; //Variable to track what index of the result string we are at. Helps with mem access.
    //Step 1: Conversion of input string to binary and appending it to the result string.
    for(int i = 0; i < password_len; i++)
    {
        strncpy(result + (32 * i), decimal_to_binary((int)(password[i])), 32);
        result_index += 32;
    }
    result[result_index] = '\0'; //Null terminate the string

    //Step 2: Initialization of 5 random strings of hexadecimal characters.
    char *H0 = "01100111110111100010101000000001"; //0x67de2a01
    char *H1 = "10111011000000111110001010001100"; //0xBB03E28C
    char *H2 = "00000001000111101111000111011100"; //0x011EF1DC
    char *H3 = "10010010100100111110100111100010"; //0x9293E9E2
    char *H4 = "11001101111011110010001110101001"; //0xCDEF23A9

    //Step 3: Padding of string until it reaches a length of a multiple of 512.
    bool first_bit = false;
    /*Let's say for example the length of the binary representation of the input password was 24 bits long.
     * We want to pad the string until it reaches a length of 64 less than a multiple of 512.
     * 512 - 64 = 448. This means that when we take length / 512, we should get a remainder of 448.
     * While we don't have a remainder of 448, we will pad the first char a '1' then the rest '0'.
     */
    for(;;)
    {
        if(!first_bit)
        {
            result[result_index] = '1';
            first_bit = true;
        } else result[result_index] = '0';
        result_index++;
        if(result_index % 512 == 448) break;
    }
    memset(&result[result_index], '0', 32);
    result_index += 32;
    strncpy(&result[result_index], decimal_to_binary((int) (32 * password_len)), 32);
    result_index += 32;
    result[result_index] = '\0';

    /*Step 4: Split string into 512-char chunks, then split each chunk into 16 32-char words.
     * Let's just enforce a 14 character password limit, so we only have a maximum of 1 512-char chunk.
    */
    char **chunks = malloc(sizeof(char*));
    char **words = malloc(16 * sizeof(char*));
    chunks[0] = malloc(513);
    strncpy(chunks[0], result, 512);
    chunks[0][512] = '\0';
    result += 512;
    for(int j = 0; j < 16; j++)
    {
        words[j] = malloc(33);
        strncpy(words[j], chunks[0], 32);
        words[j][32] = '\0';
        chunks[0] += 32;
    }
    chunks[0] -= 512;
    result -= 512;

    //Step 5: Perform xor and circular shift on words. Increase word count to 80 from 16 for each chunk.
    char **resized_words = realloc(words, 80 * sizeof(char*));
    for(int i = 16; i < 80; i++)
    {
        resized_words[i] = malloc(33);
        resized_words[i] = circular_shift(xor_bit_string(resized_words[i - 16],
                                                         xor_bit_string(resized_words[i - 14],
                                                                        xor_bit_string(resized_words[i - 3],
                                                                                       resized_words[i - 8]))), 1);
        resized_words[i][32] = '\0';
    }

    //Step 6: A = H0, B = H1, C = H2, D = H3, E = H4 (these variables will be used later, might seem redundant now)
    char *A = H0;
    char *B = H1;
    char *C = H2;
    char *D = H3;
    char *E = H4;

    //Step 7: Iterate through all 80 words to perform calculations.
    for(int i = 0; i < 80; i++)
    {
        //TEMP = S^5(A) + f(i; B, C, D) + E + W(i) + K(i)
        char *temp = malloc(33);
        //S^5(A)
        char *shift_a = circular_shift(A, 5);
        //f(i; B, C, D) and K(i)
        char *f, *K;
        if(i >= 0 && i <= 19)
        {
            f = or_bit_string(and_bit_string(B, C), and_bit_string(not_bit_string(B), D));
            K = "01011010100000100111100110011001"; //0x5A827999
        }
        else if(i >= 20 && i <= 39)
        {
            f = xor_bit_string(xor_bit_string(B, C), D);
            K = "01101110110110011110101110100001"; //0x63D93BA1
        }
        else if(i >= 40 && i <= 59)
        {
            f = or_bit_string(or_bit_string(and_bit_string(B, C), and_bit_string(B, D)), and_bit_string(C, D));
            K = "10001111000110111011110011011101"; //0x8F1BBCDC
        }
        else
        {
            f = xor_bit_string(xor_bit_string(B, C), D);
            K = "11001010011000101100000111010110"; //0xCA62C1D6
        }
        char *shift_a_plus_f = thirty_two_bit_adder(shift_a, f, 0);
        char *shift_a_plus_f_plus_E = thirty_two_bit_adder(shift_a_plus_f, E, 0);
        char *shift_a_plus_f_plus_E_plus_word = thirty_two_bit_adder(shift_a_plus_f_plus_E, resized_words[i], 0);
        strncpy(temp, thirty_two_bit_adder(shift_a_plus_f_plus_E_plus_word, K, 0), 32);
        temp[32] = '\0';
        E = D;
        D = C;
        C = circular_shift(B, 30);
        B = A;
        A = temp;
        char *temp_h0 = thirty_two_bit_adder(H0, A, 0);
        H0 = temp_h0; //strncpy(H0, temp_h0, 33); //Copy 32 bits plus null terminator
        char *temp_h1 = thirty_two_bit_adder(H1, B, 0);
        H1 = temp_h1; //strncpy(H1, temp_h1, 33);
        char *temp_h2 = thirty_two_bit_adder(H2, C, 0);
        H2 = temp_h2; //strncpy(H2, temp_h2, 33);
        char *temp_h3 = thirty_two_bit_adder(H3, D, 0);
        H3 = temp_h3; //strncpy(H3, temp_h3, 33);
        char *temp_h4 = thirty_two_bit_adder(H4, E, 0);
        H4 = temp_h4; //strncpy(H4, temp_h4, 33);
    }
    char *final = malloc(33);
    memset(final, '0', 33);
    final[32] = '\0';
    strncpy(final, or_bit_string(or_bit_string(or_bit_string(or_bit_string(
            circular_shift(H0, 128),circular_shift(H1, 96)), circular_shift(H2, 64)), circular_shift(H3, 32)), H4), 32);
    printf("Final: %s\n", final);
    return final;
}

int main() {
    char *a = sha_1("abc");
    free(a);
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <NTL/ZZ.h>
#include <Windows.h>

using namespace std;
using namespace NTL;

string toBinary(ZZ n)
{
	string r;
	while (n != 0) {
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}
	return r;
}

ZZ modulo(ZZ a, ZZ n) {
    ZZ r = a - (a / n) * n;
    if (r < 0) {
        r = r + n;
    }
    return r;
}

class RSA {

private:
    string msg;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890[]";
    ZZ d;
    ZZ e;
    ZZ N;
    ZZ p;
    ZZ q;

public:
    ZZ e_Receiver;
    ZZ N_Receiver;
    RSA(string directory);
    RSA(int bits);
    RSA(ZZ, ZZ);
    RSA(ZZ, ZZ, ZZ, ZZ);
    ZZ chineseRemainder(vector<vector<ZZ>>);
    string encode_message(string, ZZ, ZZ);
    string decode_message(string, ZZ, ZZ);
    string encode(string);
    string decode(string);
    long euclidAlgorithm(ZZ a, ZZ b);
    vector<ZZ> euclidExtendedAlgorithm(ZZ a, ZZ b);
    ZZ inverse(ZZ a, ZZ b);
    bool primalityTest(ZZ num);
    string block(string);
    ZZ generate_bit();
    ZZ generate_random(int bits);
    ZZ prime(int bits);
    ZZ generateRandom(int bits);
    ZZ exponenciacion(ZZ b, ZZ e);
    ZZ binaryExponentiation(ZZ a, ZZ e, ZZ n);
};

ZZ RSA::generate_bit() {

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    // Elapsed time
    // Elapsed time
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    ZZ seed(std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count());

    ZZ seed_2 = modulo(seed, ZZ(2));

    return seed_2;	
}

ZZ RSA::generate_random(int bits)
{
	ZZ random(0);
	ZZ power(2);
	random = random + (generate_bit());
	for (int i = 1;i<bits;i++) {
		random = random + (generate_bit()*power);
		power = power * 2;
	}
	return random;
}

ZZ mod(ZZ a, ZZ n) {
    ZZ r = a - (a / n) * n;
    if (r < 0) {
        r = r + n;
    }
    return r;
}

// Euclid's extended algorithm:
// Function that returns a vector that stores the values
// of the gcd between a & b, and also the x and y values
vector<ZZ> RSA::euclidExtendedAlgorithm(ZZ a, ZZ b) 
{
    // Initialization
	ZZ r_1 = a;
    ZZ r_2 = b;
    ZZ s_1 = ZZ(1);
    ZZ s_2 = ZZ(0);
	ZZ t_1 = ZZ(0);
	ZZ t_2 = ZZ(1);

	while (r_2 != 0) {

        // Quotient
		ZZ quotient = r_1 / r_2;

        // Updating r
        ZZ temp = r_2;
		r_2 = r_1 - quotient * r_2;
		r_1 = temp;
        
        // Updating s
		temp = s_2;
		s_2 = s_1 - quotient * s_2;
		s_1 = temp;

        // Updating t
		temp = t_2;
		t_2 = t_1 - quotient * t_2;
		t_1 = temp;
	}

    // Vector to store values
	vector<ZZ> result;

    // Greatest common divisor: result[0]
	result.push_back(r_1);
    // x: result[1]
	result.push_back(s_1);
    // y: result[2]
	result.push_back(t_1);

	return result;
}

string num2String(ZZ number) {
    ostringstream stringZZ;
    stringZZ << number;
    return stringZZ.str();
}

string num2String(int number) {
    ostringstream stringZZ;
    stringZZ << number;
    return stringZZ.str();
}

int string2NumInt(string message){
    int numberZZ;
    istringstream num(message);
    num >> numberZZ;
    return numberZZ;
}

ZZ string2Num(string message){
    ZZ numberZZ;
    istringstream num(message);
    num >> numberZZ;
    return numberZZ;
}

ZZ RSA::exponenciacion(ZZ b, ZZ e){
    
    ZZ result(1);

    while(e>0){
        if(e % 2)
            result = (result*b);
        b =  (b * b);
        e /= 2;
    }
    return result;
}

ZZ RSA::binaryExponentiation(ZZ a, ZZ e, ZZ n) {
	ZZ A(1);
	string bin = toBinary(e);
	for (int i = bin.size(); i != -1; i--) {
		A = modulo(A * A, n);
		if (bin[i] == '1') {
			A = modulo(A * a, n);
		}
	}
	return A;
}

bool RSA::primalityTest(ZZ n){
    
    if ((n & 1) == 0){
        return false;
    }
    ZZ s(0);
    ZZ t = n - 1;
    while ((t & 1) == 0) {
        s++;
        t >>= 1;
    }
    ZZ a(2);
    for (int i = 0; i < 10; i++){

        ZZ x = binaryExponentiation(a, t, n);
        if (x == 1 || x == (n-1))
            continue;
        for (ZZ r(0); r < (s-1); r++){
            x = binaryExponentiation(x, to_ZZ(2), n);
            if(x == 1){
                return false;
            }
            else if(x == n - 1)
                break;
        }
        if(x != n - 1 )
            return false;
        ZZ a = RandomBnd(n-3) + 3;
    }
    
    return true;
}

ZZ RSA::generateRandom(int bits){

    ZZ min(exponenciacion(to_ZZ(2), to_ZZ(bits))>>1), max(exponenciacion(to_ZZ(2), to_ZZ(bits)) - 1);

    ZZ number;
    do{
        number = RandomLen_ZZ(bits);
        // number = generate_random(bits); // No funcional para Linux
    }while(number < min || number > max);

    return number;
}

ZZ RSA::prime(int bits){

    ZZ prime;

    for (;!primalityTest(prime);prime = generateRandom(bits));

    return prime;
}

ZZ RSA::inverse(ZZ a, ZZ b)
{
    ZZ s_1 = euclidExtendedAlgorithm(a, b)[1];
    if (s_1 < 0) {
        s_1 = mod(s_1, b);
    }
    return s_1;
}

RSA::RSA(string directory) {
    this->p = 13;
	this->q = 149;
    ifstream infile(directory);

    string line;
    for(int i{0}; getline(infile, line); i++)
    {
        if(i == 2) {
            this->N_Receiver = string2Num(line);
        }
        else if(i == 3) {
            this->e_Receiver = string2Num(line);
        }
        else if(i == 7) {
            this->N = string2Num(line);
        }
        else if(i == 8) {
            this->e = string2Num(line);
        }
    }
	ZZ phiN = (p - 1) * (q - 1);
	this->d = inverse(e, phiN);
}

RSA::RSA(ZZ e, ZZ N) {
    this->p = 17;
	this->q = 59;
	this->N = p * q;
	ZZ phiN = (p - 1) * (q - 1);
	this->d = inverse(e, phiN);
}


RSA::RSA(ZZ p, ZZ q, ZZ e, ZZ d){
    this->p = p;
    this->q = q;
    this->N = p * q;
    this->e = e;
    this->d = d;
}

ZZ binaryEuclidAlgorithm(ZZ a, ZZ b) {
    ZZ g = ZZ(1);
    while ((mod(a, ZZ(2)) == 0) && (mod(b, ZZ(2)) == 0)) {
        a = a / 2;
        b = b / 2;
        g = 2 * g;
    }
    while (a != 0) {
        if (mod(a, ZZ(2)) == 0) {
            a = a / 2;
        }
        else if (mod(b, ZZ(2)) == 0) {
            b = b / 2;
        }
        else {
            ZZ t = abs(a - b) / 2;
            if (a >= b) {
                a = t;
            }
            else {
                b = t;
            }
        }
    }
    return g * b;
}

RSA::RSA(int bits) {
    this-> p = prime(bits);
    this-> q = prime(bits);
    this-> N = p * q;
    
    ZZ phiN = (p - 1) * (q - 1);
    
    do{
        this-> e = generateRandom(bits);
    } while(binaryEuclidAlgorithm(this->e, phiN) != 1);
    
    this-> d = inverse(this->e, phiN);

    cout << "-------------------- Valores generados --------------------" << endl;
    cout << "- Valor p  -" << endl
         << p << endl << endl;
    cout << "- Valor q -" << endl
         << q << endl << endl;;
    cout << "- Valor N -" << endl
         << N << endl << endl;
    cout << "- Valor e -" << endl
         << e << endl << endl;
    cout << "- Valor d -" << endl 
         << d << endl << endl;
}

void addZeros(int size, string &block) {
	string zeros(size - block.size(), '0');
	zeros += block;
	block = zeros;
}

ZZ phi(ZZ modulus)
{
    ZZ result = ZZ(1);
    for (ZZ i = ZZ(2); i < modulus; i++)
        if (binaryEuclidAlgorithm(i, ZZ(modulus)) == ZZ(1))
            result++;
    return result;
}

string convert(string message, string alphabet, int size) {
    int messageSize = message.length();
    string decodedMessage;
    int alphabetIndex = 0;
    for(int i{0}; i < messageSize; i += size) {
        alphabetIndex = string2NumInt(message.substr(i, size));
        char alphabetCharacter = alphabet[alphabetIndex];
        decodedMessage += alphabetCharacter;
    }
    return decodedMessage;
}

string RSA::block(string mensaje) {
    string mensaje_antes;
    int tamano_mensaje = mensaje.length();

    string tamano_alfabeto = num2String(alphabet.length());
    int tamano = tamano_alfabeto.length();

    for(int i = 0; i < tamano_mensaje; i++) {
        int posicion = alphabet.find(mensaje[i]);

        string tamano_posicion = num2String(posicion);
        int tamano_pos = tamano_posicion.length();

        if( tamano_pos < tamano) {
            string pos = num2String(posicion);
            addZeros(tamano, pos);
            mensaje_antes += pos;
        }
        else {
            string pos = num2String(posicion);
            mensaje_antes += pos;
        }
    }
    return mensaje_antes;
}

string RSA::encode_message(string message, ZZ exponent, ZZ modulus) {

    string codedMessage;

    string blockMessage = block(message);
    
    int blockSize = num2String(modulus).length() - 1;
    int blockMessageLength = blockMessage.length();

    for(int i = 0; i < blockMessageLength; i += blockSize){
        ZZ base(0);
        if(i + blockSize > blockMessageLength) {
            base = string2Num(blockMessage.substr(i, blockMessageLength - i));
        }
        else {
            base = string2Num(blockMessage.substr(i, blockSize));
        }

        ZZ power = binaryExponentiation(base, exponent, modulus);
        string powerString = num2String(power);
        int powerSize = powerString.length();
        
        string N_string = num2String(N);
        int N_size = N_string.length();
        if( powerSize < N_size) {
            string pos = num2String(power);
            addZeros(N_size, pos);
            codedMessage += pos;
        }
        else {
            string pos = num2String(power);
            codedMessage += pos;
        }

    }
    return codedMessage;
}

string RSA::encode(string message) {
    ifstream infile("sign.txt");
    string text;
    string line;

    for(int i{0}; getline(infile, line); i++){
        text += line;
    }

    string rubric = encode_message(text, d, N);

    string sign = encode_message(rubric, e_Receiver, N_Receiver);

    ofstream out("digital_sign.txt");
    out << sign;
    out.close();

    string code = encode_message(message, e_Receiver, N_Receiver);

    return code;
}

ZZ RSA::chineseRemainder(vector<vector<ZZ>> ecs)
{		
	ZZ P(1);
	for (int i = 0; i < ecs.size(); i++) {
		ecs[i][0] = mod(ecs[i][0], ecs[i][1]);
		P *= ecs[i][1];
	}
	for (int i = 0; i < ecs.size(); i++) {
		ecs[i].push_back(P / ecs[i][1]);
	}
	ZZ x0(0);
	for (int i = 0; i < ecs.size(); i++) {
		x0 += mod(ecs[i][0], P) * mod(ecs[i][2], P) * mod(inverse(ecs[i][2], ecs[i][1]), P);
		x0 = mod(x0, P);
	}
	x0 = mod(x0, P);
	return x0;
}

string RSA::decode_message(string message, ZZ exponent, ZZ modulus) {

    string decodedCode;

    string N_string = num2String(modulus);
    int N_size = N_string.length();
    int codeLength = message.length();

    string alphabetSizeString = num2String(alphabet.length());
    int alphabetSize = alphabetSizeString.length();

    for(int i = 0; i < codeLength; i += N_size){
        ZZ base(0);
        if(i + N_size > codeLength) {
            base = string2Num(message.substr(i, codeLength - i));
        }
        else {
            base = string2Num(message.substr(i, N_size));
        }

        ZZ power = binaryExponentiation(base, exponent, modulus);

        string powerString = num2String(power);
        int powerSize = powerString.length();

        if( powerSize < N_size - 1 && i + N_size < codeLength) {
            string pos = num2String(power);
            addZeros(N_size - 1, pos);
            decodedCode += pos;
        }
        else {
            string pos = num2String(power);
            decodedCode += pos;
        }

    }
    string decodedMessage = convert(decodedCode, alphabet, alphabetSize);
    return decodedMessage;
}

string RSA::decode(string message) {
    ifstream infile("digital_sign.txt");
    string line;
    for(; getline( infile, line ); );

    string decodedSign = decode_message(line, d, N);

    ifstream indirectory("directory.txt");

    string text;
    ZZ e_Emitter;
    ZZ N_Emitter;

    for(int i{0}; getline(indirectory, text); i++)
    {
        if(i == 7) {
            N_Emitter = string2Num(text);
        }     
        else if(i == 8) {
            e_Emitter = string2Num(text);
        }
    }
    
    string sign = decode_message(decodedSign, e_Emitter, N_Emitter);

    ofstream out("sign_test.txt");
    out << sign;
    out.close();

    string decodedCode = decode_message(message, d, N);
    return decodedCode;
}

int main() {

    int opt;

    cout << "Choose an option" << endl;
    cout << right << setw(12)
              << "Encode (1)" << endl;
    cout << right << setw(12)
              << "Decode (2)" << endl;
    cout << right << setw(12)
              << "Generate keys (3)" << endl;
    cout << "Option: ";
    cin >> opt;
    cin.ignore();

    if ((opt != 1) && (opt != 2) && (opt != 3)) {
        return 0;
    }

    // Objeto Receptor:
    // - Envía la clave pública e
    // - Envía el producto N
    // Directorio público
    RSA Receiver(ZZ(3), ZZ(1003));
    // Objeto Emisor:
    RSA Emitter("directory.txt");

    if (opt == 1) {
        /*string message;
        cout << "Enter message: ";
        (void) getline(cin, message);*/

        ifstream infile("message.txt");
        string line;
        for(; getline( infile, line ); );

        string code = Emitter.encode(line);

        cout << "\nEncoded message: " << code;

        ofstream out("encode.txt");
        out << code;
        out.close();
    }
    else if (opt == 2) {
        /*string message;
        cout << "Enter message: ";
        (void) getline(cin, message);*/

        ifstream infile("encode.txt");
        string line;
        for(; getline( infile, line ); );

        string code = Receiver.decode(line);

        cout << "\nDecoded message: " << code;

        ofstream out("decode.txt");
        out << code;
        out.close();
    }
    else if (opt == 3) {
        RSA Bits(1024);
    }

}
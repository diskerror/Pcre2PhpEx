# Pcre2
This is a PHP extension that compiles a PCRE2 regular expression as separate step from the comparison step. Run time is only slightly faster than the builtin PCRE API for a single compile and match. This implimentation of PCRE2 shines when a regular expression is reused multiple times. It requires [PCRE2](http://www.pcre.org) and [PHP-CPP](http://www.php-cpp.com/) to be installed on the local system.

The extension makefile has been tested on Debian 8 with PHP 7.2, PCRE2 10.31, and PHP-CPP master branch of at least 2/9/18 which is required for PHP 7.2.

*Note:* passing PHP arrays by reference doesn't work in version 2.0.0 and later of PHP-CPP;

## Usage
In PHP, the PCRE function:
```
$subject = 'abacadabra';
$result = preg_replace('/a/u', ' ', $subject);
$this->assertEquals($result, ' b c d br ');

$result = (bool)preg_match('/a/u', $subject);
$this->assertTrue($result);

$matches = [];
$result = preg_match('/a/u', $subject, $matches);  //  1
$this->assertEquals($matches, ['a']);
```
Is equivalent to:
```
//  UTF is the default
$subject = 'abacadabra';
$replacer = new \Diskerror\Pcre2\Replacer('a', ' ');
$result = $replacer->replace($subject);
$this->assertEquals($result, ' b c d br ');

$matcher = new \Diskerror\Pcre2\Matcher('a');
$result = $matcher->hasMatch($subject);
$this->assertTrue($result);

$matches = $matcher->match($subject);  //  "$matcher" from above
$this->assertEquals($matches, ['a']);
```
This will perform replacements on multiple strings with only one compile step, and without needing them to be gathered into a single array.

## Requirements For Compiling
GCC, Make, and the standard libraries are required to build and install the custom extension, as is the PHP development library. You'll need to have experience with this.

CentOS 6 requires at least devtoolset-2 to compile [PHP-CPP](http://www.php-cpp.com/).
```
 > cd /etc/yum.repos.d
 > wget http://people.centos.org/tru/devtools-2/devtools-2.repo
 > yum --enablerepo=testing-devtools-2-centos-6 install devtoolset-2-gcc devtoolset-2-gcc-c++
 > scl enable devtoolset-2 bash
```

### PCRE2
The PCRE2 source can be found [here](http://www.pcre.org).
```
 > ./configure --enable-jit --enable-newline-is-anycrlf
 > make
 > sudo make install
```

### PHP-CPP
The Copernica [PHP-CPP on GitHub](https://github.com/CopernicaMarketingSoftware/PHP-CPP) library is used to build this extension.
```
 > make release
 > sudo make install
```
Just using ```make``` will create a slower debug version.

O Formato Padrão FITS (Flexible Image Transport System) é utilizado em astronomia para normalizar a transmissão de ficheiros e assim marcar os ficheiros com toda a informação necessária para o processamento por diferentes equipas.

encontra-se definido em: Pela NASA na ligação [FITS Standard](http://fits.gsfc.nasa.gov/fits_standard.html)

pode consultar-se na versão PDF na IAU(União Astronómica Internacional) na ligação [ IAU FITS Working Group](http://fits.gsfc.nasa.gov/standard30/fits_standard30aa.pdf)

pode ainda consultar-se as palavras chave de um ficheiro FITS em [FITS Keywords](http://fits.gsfc.nasa.gov/fits_dictionary.html)

e apresenta-se de seguida As palavras chave Base que devem estar contidas num ficheiro FITS.

This data dictionary lists the 53 keywords currently defined in the
FITS Standard:

(blank)  CROTAn   EQUINOX  NAXISn   TBCOLn   TUNITn
AUTHOR   CRPIXn   EXTEND   OBJECT   TDIMn    TZEROn
BITPIX   CRVALn   EXTLEVEL OBSERVER TDISPn   XTENSION
BLANK    CTYPEn   EXTNAME  ORIGIN   TELESCOP
BLOCKED  DATAMAX  EXTVER   PCOUNT   TFIELDS
BSCALE   DATAMIN  GCOUNT   PSCALn   TFORMn
BUNIT    DATE     GROUPS   PTYPEn   THEAP
BZERO    DATE-OBS HISTORY  PZEROn   TNULLn
CDELTn   END      INSTRUME REFERENC TSCALn
COMMENT  EPOCH    NAXIS    SIMPLE   TTYPEn

---------------------------------------------------------------------

KEYWORD:   (blank)
REFERENCE: FITS Standard
STATUS:    reserved
HDU:       any
VALUE:     none
COMMENT:   descriptive comment
DEFINITION: Columns 1-8 contain ASCII blanks. This keyword has no
associated value.  Columns 9-80 may contain any ASCII text.  Any number
of card images with blank keyword fields may appear in a header.

KEYWORD:   AUTHOR
REFERENCE: FITS Standard
STATUS:    reserved
HDU:       any
VALUE:     string
COMMENT:   author of the data
DEFINITION: The value field shall contain a character string
identifying who compiled the information in the data associated with
the header. This keyword is appropriate when the data originate in a
published paper or are compiled from many sources.

KEYWORD:   BITPIX
REFERENCE: FITS Standard 
STATUS:    manditory
HDU:       any
VALUE:     integer
RANGE:     -64,-32,8,16,32
COMMENT:   bits per data value
DEFINITION: The value field shall contain an integer.  The absolute
value is used in computing the sizes of data structures.  It shall
specify the number of bits that represent a data value.

KEYWORD:   BLANK
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     integer
COMMENT:   value used for undefined array elements
DEFINITION: This keyword shall be used only in primary array headers or
IMAGE extension headers with positive values of BITPIX (i.e., in arrays
with integer data).  Columns 1-8 contain the string, `BLANK   ' (ASCII
blanks in columns 6-8).  The value field shall contain an integer that
specifies the representation of array values whose physical values are
undefined.

KEYWORD:   BLOCKED
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       primary
VALUE:     logical
COMMENT:   is physical blocksize a multiple of 2880?
DEFINITION: This keyword may be used only in the primary header.  It
shall appear within the first 36 card images of the FITS file.  (Note:
This keyword thus cannot appear if NAXIS is greater than 31, or if
NAXIS is greater than 30 and the EXTEND keyword is present.) Its
presence with the required logical value of T advises that the physical
block size of the FITS file on which it appears may be an integral
multiple of the logical record length, and not necessarily equal to
it.  Physical block size and logical record length may be equal even if
this keyword is present or unequal if it is absent.  It is reserved
primarily to prevent its use with other meanings. Since the issuance of
version 1 of the standard, the BLOCKED keyword has been deprecated.

KEYWORD:   BSCALE
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     real
DEFAULT:   1.0
COMMENT:   linear factor in scaling equation
DEFINITION: This keyword shall be used, along with the BZERO keyword,
when the array pixel values are not the true physical values, to
transform the primary data array values to the true physical values
they represent, using the equation: physical_value = BZERO + BSCALE *
array_value.  The value field shall contain a floating point number
representing the coefficient of the linear term in the scaling
equation, the ratio of physical value to array value at zero offset.
The default value for this keyword is 1.0.

KEYWORD:   BUNIT
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     string
COMMENT:   physical units of the array values
DEFINITION: The value field shall contain a character string,
describing the physical units in which the quantities in the array,
after application of BSCALE and BZERO, are expressed.   The units of
all FITS header keyword values, with the exception of measurements of
angles, should conform with the recommendations in the IAU Style
Manual. For angular measurements given as floating point values and
specified with reserved keywords, degrees are the recommended units
(with the units, if specified, given as 'deg').

KEYWORD:   BZERO
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     real
DEFAULT:   0.0
COMMENT:   zero point in scaling equation
DEFINITION: This keyword shall be used, along with the BSCALE keyword,
when the array pixel values are not the true physical values, to
transform the primary data array values to the true values using the
equation: physical_value = BZERO + BSCALE * array_value. The value field
shall contain a floating point number representing the physical value
corresponding to an array value of zero.  The default value for this
keyword is 0.0.

KEYWORD:   CDELTn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     real
COMMENT:   coordinate increment along axis
DEFINITION: The value field shall contain a floating point number
giving the partial derivative of the coordinate specified by the CTYPEn
keywords with respect to the pixel index, evaluated at the reference
point CRPIXn, in units of the coordinate specified by  the CTYPEn
keyword.  These units must follow the prescriptions of section 5.3 of
the FITS Standard.

KEYWORD: COMMENT
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     none
COMMENT:   descriptive comment
DEFINITION: This keyword shall have no associated value; columns 9-80
may contain any ASCII text.  Any number of COMMENT card images may
appear in a header.

KEYWORD:   CROTAn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     real
UNITS:     degrees
COMMENT:   coordinate system rotation angle
DEFINITION: This keyword is used to indicate a rotation from a standard
coordinate system described by the CTYPEn to a different coordinate
system in which the values in the array are actually expressed. Rules
for such rotations are not further specified in the Standard; the
rotation should be explained in comments. The value field shall contain
a floating point number giving the rotation angle in degrees between
axis n and the direction implied by the coordinate system defined by
CTYPEn.

KEYWORD:   CRPIXn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     real
COMMENT:   coordinate system reference pixel
DEFINITION: The value field shall contain a floating point number,
identifying the location of a reference point along axis n, in units of
the axis index.  This value is based upon a counter that runs from 1 to
NAXISn with an increment of 1 per pixel.  The reference point value
need not be that for the center of a pixel nor lie within the actual
data array.  Use comments to indicate the location of the index point
relative to the pixel.

KEYWORD:   CRVALn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     real
COMMENT:   coordinate system value at reference pixel
DEFINITION: The value field shall contain a floating point number,
giving the value of the coordinate specified by the CTYPEn keyword at
the reference point CRPIXn. Units must follow the prescriptions of
section 5.3 of the FITS Standard.

KEYWORD:   CTYPEn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     string
COMMENT:   name of the coordinate axis
DEFINITION: The value field shall contain a character string, giving
the name of the coordinate represented by axis n.

KEYWORD:   DATAMAX
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     real
COMMENT:   maximum data value
DEFINITION: The value field shall always contain a floating point
number, regardless of the value of BITPIX. This number shall give the
maximum valid physical value represented by the array, exclusive of any
special values.

KEYWORD:   DATAMIN
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       image
VALUE:     real
COMMENT:   minimum data value
DEFINITION: The value field shall always contain a floating point
number, regardless of the value of BITPIX. This number shall give the
minimum valid physical value represented by the array, exclusive of any
special values.

KEYWORD:   DATE
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     string
COMMENT:   date of file creation
DEFINITION: The date on which the HDU was created, in the format
specified in the FITS Standard.  The old date format was 'yy/mm/dd' and
may be used only for dates from 1900 through 1999.  the new Y2K
compliant date format is 'yyyy-mm-dd' or 'yyyy-mm-ddTHH:MM:SS[.sss]'.

KEYWORD:   DATE-OBS
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     string
COMMENT:   date of the observation
DEFINITION: The date of the observation, in the format specified in the
FITS Standard.  The old date format was 'yy/mm/dd' and may be used only
for dates from 1900 through 1999.  The new Y2K compliant date format is
'yyyy-mm-dd' or 'yyyy-mm-ddTHH:MM:SS[.sss]'.

KEYWORD:   END
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       any
VALUE:     none
COMMENT:   marks the end of the header keywords
DEFINITION: This keyword has no associated value.  Columns 9-80 shall
be filled with ASCII blanks.

KEYWORD:   EPOCH
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     real
COMMENT:   equinox of celestial coordinate system
DEFINITION: The value field shall contain a floating point number
giving the equinox in years for the celestial coordinate system in
which positions are expressed.  Starting with Version 1, the Standard
has deprecated the use of the EPOCH keyword and thus it shall not be
used in FITS files created after the adoption of the standard; rather,
the EQUINOX keyword shall be used.

KEYWORD:   EQUINOX
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     real
COMMENT:   equinox of celestial coordinate system
DEFINITION: The value field shall contain a floating point number
giving the equinox in years for the celestial coordinate system in
which positions are expressed.

KEYWORD:   EXTEND
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       primary
VALUE:     logical
COMMENT:   may the FITS file contain extensions?
DEFINITION:  If the FITS file may contain extensions, a card image with
the keyword EXTEND and the value field containing the logical value T
must appear in the  primary header immediately after the last NAXISn
card image, or, if NAXIS=0, the NAXIS card image.  The presence of this
keyword with the value T in the primary header does not require that
extensions be present.

KEYWORD:   EXTLEVEL
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       extension
VALUE:     integer
RANGE:     [1:]
DEFAULT:   1
COMMENT:   hierarchical level of the extension
DEFINITION: The value field shall contain an integer, specifying the
level in a hierarchy of extension levels of the extension header
containing it.  The value shall be 1 for the highest level; levels with
a higher value of this keyword shall be subordinate to levels with a
lower value. If the EXTLEVEL keyword is absent, the file should be
treated as if the value were 1. This keyword is used to describe an
extension and should not appear in the primary header.

KEYWORD:   EXTNAME
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       extension
VALUE:     string
COMMENT:   name of the extension
DEFINITION: The value field shall contain a character string, to be
used to distinguish among different extensions of the same type, i.e.,
with the same value of XTENSION, in a FITS file.  This keyword is used
to describe an extension and should not appear in the primary header.

KEYWORD:   EXTVER
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       extension
VALUE:     integer
RANGE:     [1:]
DEFAULT:   1
COMMENT:   version of the extension
DEFINITION: The value field shall contain an integer, to be used to
distinguish among different extensions in a FITS file with the same
type and name, i.e., the same values for XTENSION and EXTNAME. The
values need not start with 1 for the first extension with a particular
value of EXTNAME and need not be in sequence for subsequent values. If
the EXTVER keyword is absent, the file should be treated as if the
value were 1.  This keyword is used to describe an extension and should
not appear in the primary header.

KEYWORD:   GCOUNT
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       extension
VALUE:     integer
COMMENT:   group count
DEFINITION: The value field shall contain an integer that shall be used
in any way appropriate to define the data structure, consistent with
Eq.  5.2 in the FITS Standard.  This keyword originated for use in FITS
Random Groups where it specifies the number of random groups present.
In most other cases this keyword will have the value 1.

KEYWORD:   GROUPS
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       groups
VALUE:     logical
COMMENT:   indicates random groups structure
DEFINITION: The value field shall contain the logical constant T.  The
value T associated with this keyword implies that random groups records
are present.

KEYWORD:   HISTORY
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     none
COMMENT:   processing history of the data
DEFINITION: This keyword shall have no associated value; columns 9-80
may contain any ASCII text.  The text should contain a history of steps
and procedures associated with the processing of the associated data.
Any number of HISTORY card images may appear in a header.

KEYWORD:   INSTRUME
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     string
COMMENT:   name of instrument
DEFINITION: The value field shall contain a character string
identifying the instrument used to acquire the data associated with the
header.

KEYWORD:   NAXIS
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       any
VALUE:     integer
RANGE:     [0:999]
COMMENT:   number of axes
DEFINITION: The value field shall contain a non-negative integer no
greater than 999, representing the number of axes in the associated
data array. A value of zero signifies that no data follow the header in
the HDU.  In the context of FITS 'TABLE' or 'BINTABLE' extensions, the
value of NAXIS is always 2.

KEYWORD:   NAXISn
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       any
VALUE:     integer
RANGE:     [0:]
COMMENT:   size of the axis
DEFINITION: The value field of this indexed keyword shall contain a
non-negative integer, representing the number of elements along axis n
of a data array.  The NAXISn must be present for all values n =
1,...,NAXIS, and for no other values of n. A value of zero for any of
the NAXISn signifies that no data follow the header in the HDU. If
NAXIS is equal to 0, there should not be any NAXISn keywords.

KEYWORD:   OBJECT
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     string
COMMENT:   name of observed object
DEFINITION: The value field shall contain a character string giving a
name for the object observed.

KEYWORD:   OBSERVER
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     string
COMMENT:   observer who acquired the data
DEFINITION: The value field shall contain a character string
identifying who acquired the data associated with the header.

KEYWORD:   ORIGIN
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     string
COMMENT:   organization responsible for the data
DEFINITION: The value field shall contain a character string
identifying the organization or institution responsible for creating
the FITS file.

KEYWORD:   PCOUNT
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       extension
VALUE:     integer
COMMENT:   parameter count
DEFINITION: The value field shall contain an integer that shall be used
in any way appropriate to define the data structure, consistent with
Eq. 5.2 in the FITS Standard.   This keyword was originated for use
with FITS Random Groups and represented the number of parameters
preceding each group. It has since been used in 'BINTABLE' extensions
to represent the size of the data heap following the main data table.
In most other cases its value will be zero.

KEYWORD:   PSCALn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       groups
VALUE:     real
DEFAULT:   1.0
COMMENT:   parameter scaling factor
DEFINITION: This keyword is reserved for use within the FITS Random
Groups structure.  This keyword shall be used, along with the PZEROn
keyword, when the nth FITS group parameter value is not the true
physical value, to transform the group parameter value to the true
physical values it represents, using the equation, physical_value =
PZEROn + PSCALn * group_parameter_value.  The value field shall contain
a floating point number representing the coefficient of the linear
term, the scaling factor between true values and group parameter values
at zero offset.  The default value for this keyword is 1.0.

KEYWORD:   PTYPEn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       groups
VALUE:     string
COMMENT:   name of random groups parameter
DEFINITION: This keyword is reserved for use within the FITS Random
Groups structure.  The value field shall contain a character string
giving the name of parameter n.  If the PTYPEn keywords for more than
one value of n have the same associated name in the value field, then
the data value for the parameter of that name is to be obtained by
adding the derived data values of the corresponding parameters.  This
rule provides a mechanism by which a random parameter may have more
precision than the accompanying data array elements; for example, by
summing two 16-bit values with the first scaled relative to the other
such that the sum forms a number of up to 32-bit precision.

KEYWORD:   PZEROn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       groups
VALUE:     real
DEFAULT:   0.0
COMMENT:   parameter scaling zero point 
DEFINITION: This keyword is reserved for use within the FITS Random
Groups structure.  This keyword shall be used, along with the PSCALn
keyword, when the nth FITS group parameter value is not the true
physical value, to transform the group parameter value to the physical
value.  The value field shall contain a floating point number,
representing the true value corresponding to a group parameter value of
zero.  The default value for this keyword is 0.0.  The transformation
equation is as follows: physical_value = PZEROn + PSCALn *
group_parameter_value.

KEYWORD:   REFERENC
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     string
COMMENT:   bibliographic reference
DEFINITION: The value field shall contain a character string citing a
reference where the data associated with the header are published.

KEYWORD:   SIMPLE
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       primary
VALUE:     logical
COMMENT:   does file conform to the Standard?
DEFINITION: The SIMPLE keyword is required to be the first keyword in
the primary header of all FITS files. The value field shall contain a
logical constant with the value T if the file conforms to the
standard.  This keyword is mandatory for the primary header and is not
permitted in extension headers.  A value of F signifies that the file
does not conform to this standard.

KEYWORD:   TBCOLn
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       ASCII_table
VALUE:     integer
RANGE:     [1:]
COMMENT:   begining column number
DEFINITION: The value field of this indexed keyword shall contain an
integer specifying the column in which field n starts in an ASCII TABLE
extension.  The first column of a row is numbered 1.

KEYWORD:   TDIMn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       BINTABLE
VALUE:     string
COMMENT:   dimensionality of the array 
DEFINITION: The value field of this indexed keyword shall contain a
character string describing how to interpret the contents of field n as
a multidimensional array, providing the number of dimensions and the
length along each axis.  The form of the value is not further specified
by the Standard.  A proposed convention is described in Appendix B.2 of
the FITS Standard in which the value string has the format '(l,m,n...)'
where l, m, n,... are the dimensions of the array.

KEYWORD:   TDISPn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       table
VALUE:     string
COMMENT:   display format
DEFINITION: The value field of this indexed keyword shall contain a
character string describing the format recommended for the display of
the contents of field n.  If the table value has been scaled, the
physical value shall be displayed.  All elements in a field shall be
displayed with a single, repeated format. For purposes of display, each
byte of bit (type X) and byte (type B) arrays is treated as an unsigned
integer. Arrays of type A may be terminated with a zero byte.  Only the
format codes in Table 8.6, discussed in section 8.3.4 of the FITS
Standard, are permitted for encoding. The format codes must be
specified in upper case.  If the Bw.m, Ow.m, and Zw.m formats are not
readily available to the reader, the Iw.m display format may be used
instead, and if the ENw.d and ESw.d formats are not available, Ew.d may
be used.  The meaning of this keyword is not defined for fields of type
P in the Standard but may be defined in conventions using such fields.

KEYWORD:   TELESCOP
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       any
VALUE:     string
COMMENT:   name of telescope
DEFINITION: The value field shall contain a character string
identifying the telescope used to acquire the data associated with the
header.

KEYWORD:   TFIELDS
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       table
VALUE:     integer
RANGE:     [0:999]
COMMENT:   number of columns in the table
DEFINITION: The value field shall contain a non-negative integer
representing the number of fields in each row of a 'TABLE' or
'BINTABLE' extension.  The maximum permissible value is 999.

KEYWORD:   TFORMn
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       table
VALUE:     string
COMMENT:   column data format
DEFINITION: The value field of this indexed keyword shall contain a
character string describing the format in which field n is encoded in a
'TABLE' or 'BINTABLE' extension.

KEYWORD:   THEAP
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       BINTABLE
VALUE:     integer
COMMENT:   offset to starting data heap address
DEFINITION: The value field of this keyword shall contain an integer
providing the separation, in bytes, between the start of the main data
table and the start of a supplemental data area called the heap.  The
default value shall be the product of the values of NAXIS1 and NAXIS2.
This keyword shall not be used if the value of PCOUNT is zero.  A
proposed application of this keyword is presented in Appendix B.1 of
the FITS Standard.

KEYWORD:   TNULLn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       table
VALUE:     integer or string
COMMENT:   value used to indicate undefined table element
DEFINITION: In ASCII 'TABLE' extensions, the value field for this
indexed keyword shall contain the character string that represents an
undefined value for field n.  The string is implicitly blank filled to
the width of the field.  In binary 'BINTABLE' table extensions, the
value field for this indexed keyword shall contain the integer that
represents an undefined value for field n of data type B, I, or J.  The
keyword may not be used in 'BINTABLE' extensions if field n is of any
other data type.

KEYWORD:   TSCALn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       table
VALUE:     real
DEFAULT:   1.0
COMMENT:   linear data scaling factor
DEFINITION: This indexed keyword shall be used, along with the TZEROn
keyword, when the quantity in field n does not represent a true
physical quantity.  The value field shall contain a floating point
number representing the coefficient of the linear term in the equation,
physical_value = TZEROn + TSCALn * field_value, which must be used to
compute the true physical value of the field, or, in the case of the
complex data types C and M, of the real part of the field with the
imaginary part of the scaling factor set to zero.  The default value
for this keyword is 1.0.  This keyword may not be used if the format of
field n is A, L, or X.

KEYWORD:   TTYPEn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       table
VALUE:     string
COMMENT:   column name
DEFINITION: The value field for this indexed keyword shall contain a
character string, giving the name of field n.  It is recommended that
only letters, digits, and underscore (hexadecimal code 5F, ('_') be
used in the name.  String comparisons with the values of TTYPEn
keywords should not be case sensitive.  The use of identical names for
different fields should be avoided.

KEYWORD:   TUNITn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       table
VALUE:     string
COMMENT:   column units
DEFINITION: The value field shall contain a character string describing
the physical units in which the quantity in field n, after any
application of TSCALn and TZEROn, is expressed.   The units of all FITS
header keyword values, with the exception of measurements of angles,
should conform with the recommendations in the IAU Style Manual. For
angular measurements given as floating point values and specified with
reserved keywords, degrees are the recommended units (with the units,
if specified, given as 'deg').

KEYWORD:   TZEROn
REFERENCE: FITS Standard 
STATUS:    reserved
HDU:       table
VALUE:     real
DEFAULT:   0.0
COMMENT:   column scaling zero point
DEFINITION: This indexed keyword shall be used, along with the TSCALn
keyword, when the quantity in field n does not represent a true
physical quantity.  The value field shall contain a floating point
number representing the true physical value corresponding to a value of
zero in field n of the FITS file, or, in the case of the complex data
types C and M, in the real part of the field, with the imaginary part
set to zero.  The default value for this keyword is 0.0.  This keyword
may not be used if the format of field n is A, L, or X.

KEYWORD:   XTENSION
REFERENCE: FITS Standard 
STATUS:    mandatory
HDU:       extension
VALUE:     string
COMMENT:   marks beginning of new HDU
DEFINITION: The value field shall contain a character string giving the
name of the extension type.  This keyword is mandatory for an extension
header and must not appear in the primary header.  For an extension
that is not a standard extension, the type name must not be the same as
that of a standard extension.
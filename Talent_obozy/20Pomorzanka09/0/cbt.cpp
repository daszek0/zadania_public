// Jakub Daszkiewicz
// zadanie Ciąg Bajtazara (Trudny)

// cock and ball torture

#include <stdio.h>

using namespace std;

typedef long long ll;

const char poo[5] = "shit";

const ll m = 1000213769;

const ll ussr[1001] = {0, 837261609, 4060566, 542029155, 805736481, 369822202, 832649323, 210390062, 385731448, 660275288, 791123298, 249674072, 793095532, 279765975, 497272459, 762987489, 245533260, 798659188, 856781425, 842430975, 570147767, 504097881, 593489277, 994059281, 690598030, 786689922, 153492735, 383369448, 88899153, 550998976, 728000706, 920884678, 581399761, 792632352, 780334920, 186249342, 236188363, 482535566, 675273462, 100597440, 402998855, 285707049, 233545251, 375846520, 852104128, 495134503, 228127684, 173465094, 22853418, 321162060, 145530433, 930533492, 902055512, 89476608, 298730900, 842690654, 176471714, 426611529, 329927087, 151514617, 904182284, 433283203, 962927986, 996755836, 504653263, 38712640, 42465367, 570250066, 745893367, 844327896, 724265386, 60486146, 240067128, 863664516, 260648203, 178773464, 697708637, 29620991, 955321989, 748444853, 952380849, 238534291, 144317462, 387933928, 168195971, 414641534, 124264419, 594286582, 347337750, 601805840, 915393958, 547007250, 339743857, 775798793, 757776699, 704726855, 444031759, 170486000, 149957577, 529160413, 398820518, 924922357, 949987234, 724923251, 581147526, 385330667, 84239299, 181965329, 456990065, 224205682, 118117634, 152496750, 319708483, 927832622, 309616591, 668526536, 314840378, 928083457, 523944745, 128501320, 617385323, 251103337, 70458716, 637185944, 57966187, 868504974, 900584542, 996953590, 11360046, 241021768, 865748094, 354922205, 204473517, 85523802, 70281560, 783376559, 380502371, 782620225, 805184911, 596507443, 316864081, 617958423, 401343309, 984049630, 980415014, 517781157, 275409749, 337874380, 794500652, 279865729, 951947426, 311039078, 798051734, 497819208, 18887144, 980279571, 588814376, 905675949, 214873013, 936788820, 224154724, 821786578, 389083724, 945934572, 256633163, 591808912, 867164891, 96758784, 497676930, 653436462, 53258489, 295538806, 458749573, 982148535, 683135068, 592640396, 451867946, 466905547, 277394733, 195809755, 985635804, 474113807, 339146396, 869351572, 674019317, 251645343, 962696825, 653810991, 854821866, 81212968, 43444808, 934132369, 197686873, 712019408, 822806615, 849667341, 524336143, 412916048, 928435873, 519696307, 497219322, 551339146, 747988078, 912716787, 509998444, 53318280, 230833731, 34258610, 998639911, 935203847, 721300413, 865996225, 534616573, 9385383, 730903826, 421851254, 438097823, 457468494, 814656348, 78152273, 810081174, 833945087, 894484038, 856869116, 33008438, 667607593, 860549684, 81337833, 199935891, 36347993, 322895445, 225131601, 693847315, 88661457, 716184692, 562238864, 336192933, 410910095, 6875635, 887366886, 651894064, 65340339, 119573156, 894547335, 549109977, 880081555, 632103259, 652170195, 177817154, 336618188, 579798958, 599182087, 171822537, 870153447, 125263147, 223365348, 89173169, 464101835, 564079567, 894828566, 55426899, 808967731, 677580607, 801012403, 5371966, 835764912, 463814030, 905469739, 586727070, 960535170, 121511703, 335058101, 866951188, 669030315, 195824130, 382250339, 558600306, 384593651, 726554606, 426160632, 984680277, 541419257, 914052146, 74116831, 261583047, 924448279, 725547344, 987532729, 675072873, 326549465, 165253523, 354464750, 884169756, 384045994, 104046132, 611460452, 271391587, 151679985, 894081454, 305606669, 20234729, 965735656, 85628621, 798665571, 452694512, 615460381, 619559779, 564882139, 66585224, 749087997, 580036886, 791230065, 290895754, 649484979, 134486186, 183366866, 577174997, 936560816, 32584486, 713277971, 523645093, 417840480, 140211777, 736403447, 420741803, 736553760, 840588600, 485643051, 639183478, 523717842, 820581224, 58950173, 452148833, 685184524, 946822230, 458207112, 532425590, 386691569, 933630624, 286026220, 991616160, 984086761, 389607906, 784852350, 271011862, 376860208, 796200548, 178506205, 353515514, 96585020, 732518503, 666373000, 646607425, 103658100, 274143436, 931706383, 381601565, 512832349, 861862720, 754094783, 539363415, 473639269, 594007829, 450280948, 56474774, 917091769, 122195609, 780493728, 878835511, 199161147, 643435736, 108770113, 445395020, 202493971, 18463628, 444592439, 499812882, 984924185, 144827321, 20067894, 559252119, 496755850, 858933208, 610756012, 721990188, 464926069, 968691504, 452656594, 942080582, 327700448, 981437554, 784172848, 99139958, 782809000, 695549767, 341428483, 264339424, 22777373, 207926659, 998612324, 763499407, 74344358, 477658391, 410060316, 228191591, 617034561, 467888497, 89843848, 457428601, 257754769, 28222992, 517734703, 294196344, 629652894, 559173151, 111709956, 822001342, 535457458, 604370731, 535422591, 676993627, 646685020, 113986119, 158118650, 200293820, 129337721, 574408438, 804970613, 640079028, 192487073, 152963049, 793550823, 730557225, 203800691, 498393350, 234239035, 688831241, 402293040, 711752916, 357139256, 433564566, 80103481, 5388446, 829416620, 429424146, 735917925, 123458337, 246951532, 61417282, 500219268, 572913023, 802676306, 892648801, 841628718, 585316089, 362081211, 898395059, 64179358, 256960693, 569746482, 488838621, 725403724, 902559187, 682445089, 467477572, 406016720, 915867601, 483748524, 704422191, 945598036, 695418866, 226742358, 10064548, 964732975, 486206355, 775591044, 324021564, 402631818, 24498140, 398931376, 542828327, 686797909, 687221612, 523219562, 294259212, 49314969, 290506919, 363245773, 28003199, 590069974, 403876551, 630067275, 849534361, 793230509, 182372488, 873109143, 40650798, 33019924, 463829200, 64388416, 931399961, 894317074, 487873711, 583170958, 19600554, 90317428, 931218044, 464168289, 960945237, 183081272, 682999269, 628980647, 174844095, 942533196, 619042290, 794377547, 777146944, 224068835, 23490108, 722696314, 689187725, 698850448, 507551136, 227877512, 511619399, 347973686, 905961694, 767689546, 308119974, 32607127, 192234866, 862041257, 107967761, 596353584, 991443049, 25317010, 552313191, 604106343, 819619561, 990931621, 54468828, 573430921, 176625917, 622290479, 333789089, 487667987, 61158244, 212912620, 713683412, 921546233, 117678526, 497447463, 211859172, 653863247, 623582883, 592875464, 495816566, 283962055, 374499181, 493258449, 439536101, 478644222, 608062541, 814295188, 288517422, 558321503, 162189022, 104173097, 252420887, 691336361, 76542342, 720676109, 97225434, 871531933, 957469814, 898192294, 181452129, 494400633, 944849601, 100858603, 397525117, 739934196, 236278493, 924736696, 370982818, 443257259, 130965860, 699777987, 49778682, 92052454, 196226998, 877106263, 290404542, 503637284, 516826152, 863824183, 529148365, 505402324, 973843950, 334480603, 863047139, 17512416, 612488609, 746609923, 986773428, 41776850, 527875176, 425655905, 360412482, 91060518, 275962988, 606903573, 865856061, 6312542, 29854107, 919117437, 774365304, 952000806, 473743885, 544528799, 450668059, 855211858, 557979502, 664745048, 645305706, 251089601, 537446156, 831817034, 240381854, 762556310, 399605174, 194890803, 689835490, 724998643, 925411499, 843874457, 219833601, 9451553, 192435384, 116248976, 508209410, 686516249, 193436943, 164546481, 960351562, 424262987, 73901027, 637029387, 317491474, 951875172, 622064826, 883801675, 295298652, 173460140, 263357344, 369904371, 501054028, 276697001, 384461304, 987040835, 690916486, 172770295, 813115717, 118287191, 227545875, 321968046, 35445516, 865753985, 545287602, 436040362, 209601208, 823777724, 844055455, 471241463, 146476645, 494468854, 742246249, 506662455, 311043480, 346363117, 679171468, 10535711, 817339935, 87303924, 985052046, 345867247, 893606318, 634104953, 604298109, 682353452, 620002885, 999772797, 603091421, 33981869, 409507204, 8745452, 507633737, 304299603, 200977449, 673786156, 897041850, 341267351, 715369644, 927574360, 881714631, 579156471, 264603293, 231103270, 380346873, 191372501, 62032558, 656703880, 606543798, 425346023, 494792948, 623870570, 199721494, 675917113, 573739595, 874767786, 376794723, 452384013, 680981874, 175314968, 858026751, 124154279, 774020322, 434162554, 746745463, 485019229, 949571284, 852315282, 264901093, 883916567, 221704425, 760927918, 548704911, 50494223, 548318489, 970678259, 927575414, 365233701, 284983186, 584464002, 543518474, 883890361, 918973646, 457145381, 250690750, 714201352, 109950384, 59218716, 990148582, 351339747, 831111259, 651234580, 135516827, 1205670, 507378707, 814328027, 839049184, 149936247, 268133679, 628610212, 769780899, 556555623, 518720694, 29460939, 934802975, 333040595, 146036972, 63858603, 914589470, 990930765, 738009452, 319455282, 703256317, 707487966, 479621318, 619913921, 177190140, 546380360, 762363551, 900865392, 887967914, 391317220, 15802522, 476928232, 445871424, 589293817, 396429328, 979475793, 691014540, 810899059, 624612492, 992857675, 11416812, 194571229, 39052469, 576404035, 432265108, 968571763, 726156612, 889892441, 180194346, 742812201, 313228550, 656259637, 793674717, 737769522, 450860436, 964809885, 158627249, 467303412, 247700102, 59346243, 700124459, 598505119, 100385608, 574088211, 464673165, 565202673, 435538259, 375874390, 942790904, 613231727, 314110418, 315283125, 168593124, 731752643, 13992696, 647076181, 522220903, 196289975, 369032509, 793079962, 703399062, 917480348, 913370516, 46361794, 291488738, 290907719, 167096041, 10122601, 889706820, 703581769, 878240113, 810633924, 923278241, 755558741, 322951892, 338826482, 179119564, 917566963, 280958105, 21646556, 779364274, 81707811, 561290816, 213261145, 249656348, 523505052, 817610605, 318283539, 652383355, 416860019, 638343697, 760952187, 52649579, 316081636, 429839759, 812148223, 137488263, 336125853, 475840804, 992119310, 244448575, 409164303, 373584240, 843108861, 320826442, 43848993, 687714565, 689624077, 913844757, 341680396, 544244395, 894454496, 818465019, 762260847, 138542500, 99922209, 683581136, 953769053, 535861410, 330328128, 633743441, 777122234, 412865900, 163045206, 577662032, 407181208, 52483668, 257230224, 960551913, 275376768, 281890022, 420763825, 745086780, 674309763, 84258405, 312907859, 646575525, 313780392, 5789094, 621303756, 453665657, 227161012, 806716373, 932558541, 30169390, 897400340, 611693742, 219103306, 665515423, 702450521, 748748646, 55228924, 835476892, 662029312, 767543739, 379639757, 40166377, 734508927, 198615745, 995457617, 182265427, 905465070, 383617205, 234623228, 820883539, 825584849, 516409026, 55546890, 92029231, 104914498, 583948467, 223043617, 505065542, 604857864, 157645559, 773074227, 648753429, 76286271, 108276224, 351787875, 994314952, 740098430, 552783580, 572401261, 258799403, 571661029, 982488806, 704019987, 250795514, 644627753, 673468749, 1065969, 929904305, 151323242, 842274618, 54828034, 494116472, 949827020, 615225278, 497013264, 858165297, 810816411, 763693545, 269025120, 38354932, 196686430, 766748305, 601229449, 154304024, 459458867, 891612476, 189499593, 707505392, 763310742, 610585733, 337017094, 574459477, 659392136, 190095862, 353534372, 248209167, 481836064, 21693708, 456197444};

int main()
{
    ll n;
    scanf("%lld", &n);
    ll i = n - (n % 1000000);
    ll xd = ussr[n / 1000000];
    if (n < 1000000)
    {
        i = 1;
        xd = 7;
    }
    for (; i<=n; i++)
    {
        xd = (xd * xd + 1) % m;
    }
    printf("%lld", xd);
    return 0;
}
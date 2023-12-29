const unsigned char patterns[] = { 
	0, /* Null pattern - no light/led */
/* WHITE	1	FL W 5s	Chicken	26	1	1 */
/*	index 1 - [('W', 1000), ('Off', 4000)] */
	4,16,0,
	/*		1,1 Chicken FL W 5s */
/* WHITE	2	Fl(4) W 20s	Point of Ayre	3	1	2 */
/*	index 4 - [('W', 500), ('Off', 1000), ('W', 500), ('Off', 1000), ('W', 500), ('Off', 1000), ('W', 500), ('Off', 15000)] */
	   1,9,1,9,1,0,1,50,0,
	/*		1,2 Point of Ayre Fl(4) W 20s 

	Was:		2,4,2,4,2,4,2,60,0, 

	                Actual patter is 0.2, 2.3, 0.2, 2.3, 0.2, 12.3 according to a 1970 page at Trinity House.

			So updated to be closer to this.
	*/

/* GREEN	1	Fl G 3s	Douglas	13	2	1 */
/*	index 13 - [('G', 1000), ('Off', 2000)] */
	4,8,0,
	/*		2,1 Douglas Fl G 3s */
/* GREEN	2	Iso G 2s	Castletown	18	2	2 */
/*	index 16 - [('G', 1000), ('Off', 1000)] */
	4,4,0,
	/*		2,2 Castletown Iso G 2s */
/* GREEN	3	Q G	Ramsey	6	2	3 */
/*	index 19 - [('G', 250), ('Off', 750)] */
	1,3,0,
	/*		2,3 Ramsey Q G */
/* GREEN	4	ISO G 4s	Ramsey	5	2	4 */
/*	index 22 - [('G', 2000), ('Off', 2000)] */
	8,8,0,
	/*		2,4 Ramsey ISO G 4s */
/* GREEN	5	Oc G 7s	Peel	30	2	5 */
/*	index 25 - [('G', 6000), ('Off', 1000)] 
	- castle jetty */
	20,8,0,
/* Trinity says:: 5 on, Occ 2. - so updated */

	/*		2,5 Peel Oc G 7s */
/* GREEN	6	Oc G 5s	Port erin	28	2	6 */
/*	index 28 - [('G', 4000), ('Off', 1000)] */
	16,4,0,
	/*		2,6 Port erin Oc G 5s */
/* GREEN	7	Oc G 3s	Laxey	11	2	7 */
/*	index 31 - [('G', 2000), ('Off', 1000)] */
	8,4,0,
	/*		2,7 Laxey Oc G 3s */
/* YELLOW	2	Q(2) W 5s	Carrick	23	3	2 */
/*	index 34 - [('W', 500), ('Off', 250), ('W', 4000), ('Off', 250)] 
	index 34 - [('W', 250), ('Off', 750), ('W',  250), ('Off', 4000 - 1250 = 2750 )] -- hand edited - based on http://www.highsea.cz/nga/Pub114bk.pdf*/
	1,3,1,11,0,
	/*		3,2 Carrick Q(2) W 5s */
/* YELLOW	3	Fl(2) W 30s	Castletown	22	3	3 */
/*	index 39 - [('W', 500), ('Off', 1000), ('W', 500), ('Off', 28000)] */
	2,4,2,112,0,
	/*		3,3 Castletown Fl(2) W 30s */
/* YELLOW	4	Oc W 7s	Peel	32	3	4 */
	/* repeated pattern; reusing sequence at idx 25 */
		/* 24,4,3 4 Peel */
		/* [('W', 6000), ('Off', 1000)] */
/* YELLOW	5	Fl(3) W 30s	Maughold head	9	3	5 */
/*	index 44 - [('W', 500), ('Off', 1000), ('W', 500), ('Off', 1000), ('W', 500), ('Off', 26500)] */
	2,4,2,4,2,106,0,
	/*		3,5 Maughold head Fl(3) W 30s */
/* YELLOW	6	FL 10s	Douglas	15	3	6 */
/*	index 51 - [('W', 1000), ('Off', 9000)] */
	4,36,0,
	/*		3,6 Douglas FL 10s */
/* YELLOW	7	Q(9) W 10s	Point of Ayre	1	3	7 */
/*	index 54 - [('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 3750), ('Off', 250)] */
/*	index 54 - [('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W',  250), ('Off', 3750)] << hand edited*/
	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,15,1,0,
	/*		3,7 Point of Ayre Q(9) W 10s */
/* YELLOW	8	Q(9) W 15s	Point of Ayre	2	3	8 */
/*	index 73 - [('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 8750), ('Off', 250)] */
/*	index 73 - [('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W', 500), ('Off', 250), ('W',  250), ('Off', 8750)] << hand edited */
	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,35,1,0,
	/*		3,8 Point of Ayre Q(9) W 15s */
/* RED	1	F R	Douglas,inland	16	4	1 */
/*	index 92 - [('R', 1)] */
	112,0,
	/*		4,1 Douglas,inland F R */
/* RED	2	F R	Douglas,inland	17	4	2 */
	/* repeated pattern; reusing sequence at idx 92 */
		/* 112,4 2 Douglas,inland */
		/* [('R', 1)] */
/* RED	3	F R	Snowfell	12	4	3 */
	/* repeated pattern; reusing sequence at idx 92 */
		/* 112,4 3 Snowfell */
		/* [('R', 1)] */
/* RED	4	FL R 5s	Douglas	14	4	4 */
	/* repeated pattern; reusing sequence at idx 1 */
		/* 4,16,4 4 Douglas */
		/* [('R', 1000), ('Off', 4000)] */
/* RED	6	F R	college	19	4	6 */
	/* repeated pattern; reusing sequence at idx 92 */
		/* 112,4 6 college */
		/* [('R', 1)] */
/* RED	7	Oc R 15s	Castletown	20	4	7 */
/*	index 94 - [('R', 14000), ('Off', 1000)] */
	56,4,0,
	/*		4,7 Castletown Oc R 15s */
/* RED	8	Oc R 3s	Port st Mary	24	4	8 */
	/* repeated pattern; reusing sequence at idx 31 */
		/* 8,4,4 8 Port st Mary */
		/* [('R', 2000), ('Off', 1000)] */
/* RED	9	FL R 3s	calf	25	5	1 */
	/* repeated pattern; reusing sequence at idx 13 */
		/* 4,8,5 1 calf */
		/* [('R', 1000), ('Off', 2000)] */
/* RED	10	Fl R 5s	Victorya Pier	8	5	2 */
	/* repeated pattern; reusing sequence at idx 1 */
		/* 4,16,5 2 Victorya Pier */
		/* [('R', 1000), ('Off', 4000)] */
/* RED	11	ISO R 5s	Ramsey	7	5	3 */
/*	index 97 - [('R', 2500), ('Off', 2500)] */
	10,10,0,
	/*		5,3 Ramsey ISO R 5s */
/* RED	13	F R	Ramsey, bridge	4	5	5 */
	/* repeated pattern; reusing sequence at idx 92 */
		/* 112,5 5 Ramsey, bridge */
		/* [('R', 1)] */
/* RED	14	Oc R 3s	Laxey	10	5	6 */
	/* repeated pattern; reusing sequence at idx 31 */
		/* 8,4,5 6 Laxey */
		/* [('R', 2000), ('Off', 1000)] */
/* RED	15	Fl R 3s	Casteltown, Leeharia rock	21	5	7 */
	/* repeated pattern; reusing sequence at idx 13 */
		/* 4,8,5 7 Casteltown, Leeharia rock */
		/* [('R', 1000), ('Off', 2000)] */
/* RED	16	F R	Port erin	29	5	8 */
	/* repeated pattern; reusing sequence at idx 92 */
		/* 112,5 8 Port erin */
		/* [('R', 1)] */
/* RED	17	F R	Port erin	27	6	1 */
	/* repeated pattern; reusing sequence at idx 92 */
		/* 112,6 1 Port erin */
		/* [('R', 1)] */
/* RED	18	Oc R 7s	Peel	31	6	2 */
	/* repeated pattern; reusing sequence at idx 25 */
		/* 24,4,6 2 Peel */
		/* [('R', 6000), ('Off', 1000)] */
};
const unsigned char idx[48] = {
		/* Grid,Seg	Location and pattern */
	1,	/* 1,1		Chicken FL W 5s */
	4,	/* 1,2		Point of Ayre Fl(4) W 20s */
	0,	/* 1,3		na  */
	0,	/* 1,4		na  */
	0,	/* 1,5		na  */
	0,	/* 1,6		na  */
	0,	/* 1,7		na  */
	0,	/* 1,8		na  */
	13,	/* 2,1		Douglas Fl G 3s */
	16,	/* 2,2		Castletown Iso G 2s */
	19,	/* 2,3		Ramsey Q G */
	22,	/* 2,4		Ramsey ISO G 4s */
	25,	/* 2,5		Peel Oc G 7s */
	28,	/* 2,6		Port erin Oc G 5s */
	31,	/* 2,7		Laxey Oc G 3s */
	0,	/* 2,8		na  */
	0,	/* 3,1		na  */
	34,	/* 3,2		Carrick Q(2) W 5s */
	39,	/* 3,3		Castletown Fl(2) W 30s */
	25,	/* 3,4		Peel Oc W 7s */
	44,	/* 3,5		Maughold head Fl(3) W 30s */
	51,	/* 3,6		Douglas FL 10s */
	54,	/* 3,7		Point of Ayre Q(9) W 10s */
	73,	/* 3,8		Point of Ayre Q(9) W 15s */
	92,	/* 4,1		Douglas,inland F R */
	92,	/* 4,2		Douglas,inland F R */
	92,	/* 4,3		Snowfell F R */
	1,	/* 4,4		Douglas FL R 5s */
	0,	/* 4,5		na  */
	92,	/* 4,6		college F R */
	94,	/* 4,7		Castletown Oc R 15s */
	31,	/* 4,8		Port st Mary Oc R 3s */
	13,	/* 5,1		calf FL R 3s */
	1,	/* 5,2		Victorya Pier Fl R 5s */
	97,	/* 5,3		Ramsey ISO R 5s */
	0,	/* 5,4		na  */
	92,	/* 5,5		Ramsey, bridge F R */
	31,	/* 5,6		Laxey Oc R 3s */
	13,	/* 5,7		Casteltown, Leeharia rock Fl R 3s */
	92,	/* 5,8		Port erin F R */
	92,	/* 6,1		Port erin F R */
	25,	/* 6,2		Peel Oc R 7s */
	0,	/* 6,3		na  */
	0,	/* 6,4		na  */
	0,	/* 6,5		na  */
	0,	/* 6,6		na  */
	0,	/* 6,7		na  */
	0,	/* 6,8		na  */
};
const int tock=250; /* milliSeconds */
const int lights=48; /* number of lights/entries */

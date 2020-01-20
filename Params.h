#pragma once
static const class Params {
	public:
		int maleHeight;
		int maleWidth;
		int femaleHeight;
		int femaleWidth;

		int heightStandDiviation;
		int widthStandDiviation;

		int peopleCount;

		Params() {
			maleHeight = 177;
			maleWidth = 60;
			femaleHeight = 165;
			femaleWidth = 56;
			heightStandDiviation = 8;
			widthStandDiviation = 5;
			peopleCount = 100;
		}
		Params(int PeopleCount) {
			maleHeight = 177;
			maleWidth = 60;
			femaleHeight = 165;
			femaleWidth = 56;
			heightStandDiviation = 8;
			widthStandDiviation = 5;
			peopleCount = PeopleCount;
		}
		Params(int PeopleCount, int MaleHeight, int MaleWidth, int FemaleHeight, int FemaleWidth) {
			maleHeight = MaleHeight;
			maleWidth = MaleWidth;
			femaleHeight = FemaleHeight;
			femaleWidth = FemaleWidth;
			heightStandDiviation = 8;
			widthStandDiviation = 5;
			peopleCount = PeopleCount;
		}
};
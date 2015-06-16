/*
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
Assume that the total area is never beyond the maximum possible value of int.
*/
 int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int minLeft = 0;
	int maxLeft = 0;
	int minBottom = 0;
	int maxBottom = 0;
	int minRight = 0;
	int maxRight = 0;
	int minTop = 0;
	int maxTop = 0;
	A > E ? (minLeft = E, maxLeft = A) : (minLeft = A, maxLeft = E);
	B > F ? (minBottom = F, maxBottom = B) : (minBottom = B, maxBottom = F);
	C > G ? (minRight = G, maxRight = C) : (minRight = C, maxRight = G);
	D > H ? (minTop = H, maxTop = D) : (minTop = D, maxTop = H);
	int area = (C - A) * (D - B) + (G - E) * (H - F);
	int overlap = 0;
	if (minRight <= maxLeft || maxBottom >= minTop)
		return area;
	else
		overlap = (minRight - maxLeft) * (minTop - maxBottom);
	return area - overlap;
}
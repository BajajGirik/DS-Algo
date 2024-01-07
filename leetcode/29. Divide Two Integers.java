import java.util.List;

class Solution {
    public List<Integer> returnHelper(long positiveValue, boolean isPositive) {
        if (isPositive && positiveValue > Integer.MAX_VALUE) {
            return List.of(Integer.MAX_VALUE, 1);
        }
        if (!isPositive && -positiveValue < Integer.MIN_VALUE) {
            return List.of(Integer.MIN_VALUE, 1);
        }
        int finalResult = (int)(isPositive ? positiveValue : -positiveValue);
        return List.of(finalResult, 0);
    }

    public int divide(int dividend, int divisor) {
        long finalQuotient = 0;
        long currQuotient = 0;
        long _dividend = dividend;
        long _divisor = divisor;
        boolean isPositive = _dividend < 0 == _divisor < 0;

        _dividend = Math.abs(_dividend);
        _divisor = Math.abs(_divisor);
        long initialDivisor = _divisor;

        while (_dividend >= initialDivisor) {
            if (_dividend - _divisor < 0 && _divisor != initialDivisor) {
                _divisor = initialDivisor;
                finalQuotient += currQuotient;
                currQuotient = 0;
            }

            _dividend -= _divisor;

            currQuotient = currQuotient + _divisor / initialDivisor;
            _divisor *= 2;

            List<Integer> result = this.returnHelper(currQuotient + finalQuotient, isPositive);
            if (result.get(1) == 1) {
                return result.get(0);
            }
        }

        List<Integer> result = this.returnHelper(currQuotient + finalQuotient, isPositive);
        return result.get(0);
    }
}

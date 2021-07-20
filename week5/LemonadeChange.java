class LemonadeChange {
    public boolean lemonadeChange(int[] bills) {
        changes = new HashMap<Integer, Integer>();
        changes.put(5, 0);
        changes.put(10, 0);
        changes.put(20, 0);

        for(int bill: bills){
            changes.put(bill, changes.get(bill) + 1);
            if(calc(bill - 5) != 0) return false;
        }
        return true;
    }

    private int calc(int bill){
        // 先找大钱
        while(bill >= 10 && changes.get(10) != 0){
            changes.put(10, changes.get(10) - 1);
            bill -= 10;
        }
        // 最后找小钱（否则执行结果不正确）
        while(bill >= 5 && changes.get(5) != 0){
            changes.put(5, changes.get(5) - 1);
            bill -= 5;
        }
        return bill;
    }

    private Map<Integer, Integer> changes;
        
}
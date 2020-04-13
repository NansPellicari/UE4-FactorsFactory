// Make it an Interface
class AbstractOperator {
    constructor() {
        if (this.constructor === AbstractOperator) {
            throw new TypeError('Abstract class "AbstractOperator" cannot be instantiated directly');
        }
    }

    compute(lh, rh) {
        throw new Error('You must implement this function');
    }
    getInverse() {
        throw new Error('You must implement this function');
    }
}

// Make it an Interface
class AbstractOperatorWithStack extends AbstractOperator {
    constructor() {
        super()
        if (this.constructor === AbstractOperatorWithStack) {
            throw new TypeError('Abstract class "AbstractOperatorWithStack" cannot be instantiated directly');
        }
    }

    setStack(stack) {
        throw new Error('You must implement this function');
    }
    setKeyInStack(key) {
        throw new Error('You must implement this function');
    }
}

class NullOperator extends AbstractOperator {
    constructor() {
        super();
    }
    compute(lh, rh) {
        return lh;
    }
    getInverse() {
        // should be a static property
        return this;
    }
}
class AddOperator extends AbstractOperator {
    constructor() {
        super();
    }
    compute(lh, rh) {
        return lh + rh;
    }
    getInverse() {
        // should be a static property
        return new SubtractOperator();
    }
}
class SubtractOperator extends AbstractOperator {
    constructor() {
        super();
    }
    compute(lh, rh) {
        return lh - rh;
    }
    getInverse() {
        return new AddOperator();
    }
}
class MultiplyOperator extends AbstractOperator {
    constructor() {
        super();
    }
    compute(lh, rh) {
        return lh * rh;
    }
    getInverse() {
        return new DivideOperator();
    }
}
class DivideOperator extends AbstractOperator {
    constructor() {
        super();
    }
    compute(lh, rh) {
        return lh / rh;
    }

    getInverse() {
        return new MultiplyOperator();
    }
}
class ResetOperator extends AbstractOperatorWithStack {
    constructor() {
        super();
        this.stack;
        this.key;
        // ResetOperator.resetList[this.stack.id] = [];
    }
    compute(lh, rh) {
        let maxAttempt = 10;
        const resetList = ResetOperator.resetList[this.stack.id];
        // console.log(this.stack, this.key, this.stack.get(this.key))
        let diff = this.stack.get(this.key);
        if (diff.getOperator() !== this) {
            throw new Error('the key or stack passed to the ResetOperator is not valid')
        }

        let resetDiff = diff;
        let id = resetDiff.id;
        const valReset = rh;
        let nullOpRes = new NullOperator().compute(lh, rh);
        // console.log("resetList", resetList)
        // console.log("reset---------", valReset)
        while (maxAttempt > 0 && (!resetDiff.getActivate() || resetDiff.operator instanceof ResetOperator || resetList.includes(id))) {
            const resetKey = this.key - (valReset + (10 - maxAttempt));
            if (resetKey < 0) return nullOpRes;
            // console.log("resetKey", resetKey);
            resetDiff = this.stack.get(resetKey);
            // console.log(resetDiff, resetDiff.getActivate())
            id = resetDiff.id;
            maxAttempt--;
        }

        if (resetDiff === diff) {
            console.error("reset can't be found");
            return nullOpRes;
        }
        if (!resetList.includes(id)) resetList.push(id);
        return resetDiff.getOperator().getInverse().compute(lh, resetDiff.getVal());
    }

    getInverse() {
        return new NullOperator();
    }

    setStack(stack) {
        this.stack = stack;
    }
    setKeyInStack(key) {
        this.key = key;

        if (typeof ResetOperator.resetList[this.stack.id] === 'undefined' || typeof this.stack.iterationFlags['ResetList_Created'] === 'undefined') {
            ResetOperator.resetList[this.stack.id] = [];
        }
        if (typeof this.stack.iterationFlags['ResetList_Created'] === 'undefined') {
            this.stack.iterationFlags['ResetList_Created'] = true;
        }
    }

    static resetList = {};
}

class Difficulty {
    constructor(val, operator, duration) {
        this.val = val;
        if (!(operator instanceof AbstractOperator)) {
            throw new Error('Operator should be an AbstractOperator implementation')
        }
        this.operator = operator
        this.duration = duration || 0;
        this.activationTime = 1;
        this.activate = true;
        this.id = Date.now().toString(36) + Math.random().toString(36).substr(2);
    }

    addTime(time) {
        this.activationTime += time;
    }

    getVal() {
        if (!this.getActivate()) {
            return 0;
        }
        return this.val;
    }
    getOperator() {
        if (!this.getActivate()) {
            return new NullOperator();
        }
        return this.operator;
    }

    getActivate() {
        return this.duration === 0 || this.activationTime <= this.duration;
    }
}

class DifficultyState {
    constructor(time) {
        if (typeof time !== "number") {
            throw new Error('A state has to be related to a time period')

        }
        this.operators = [];
        this.value = 0;
        this.time = time

    }

    getTime() {
        return this.time;
    }

    add(value, operator) {
        if (!(operator instanceof AbstractOperator)) {
            throw new Error('Operator should be an AbstractOperator implementation')
        }
        this.operators.push([operator, value]);
    }

    compute() {
        let value = 1;
        // console.log(this.operators);
        for (let operatorData of this.operators) {
            let [operator, coeff] = operatorData;
            value = operator.compute(value, coeff);
            // console.log(operatorName, this.operators[operatorName], operator, coeff)
        }
        this.value = value;
        return this.value;
    }

}

class DifficultyStack {
    constructor() {
        this.stack = [];
        this.time = 0;
        this.id = 'stack-' + Date.now().toString(36) + Math.random().toString(36).substr(2);
        this.iterationFlags = {};

    }

    addTime(time) {
        this.time += time
        for (let diff of this.stack) {
            diff.addTime(time);
        }
    }

    get(key) {
        return this.stack[key];
    }

    add(difficulty) {
        this.stack.push(difficulty);
    }

    getCurrentState() {
        const state = new DifficultyState(this.time);
        this.iterationFlags = {};

        for (let key in this.stack) {
            let diff = this.stack[key];
            if (diff.getOperator() instanceof AbstractOperatorWithStack) {
                diff.getOperator().setStack(this);
                diff.getOperator().setKeyInStack(key);
            }
            state.add(diff.getVal(), diff.getOperator());
        }
        return state;
    }
}

const diffsStack = new DifficultyStack();
// for now it work only for point, but should be great to create a stack different for time duration (on QTE for ex.)
diffsStack.add(new Difficulty(2, new AddOperator()));
diffsStack.add(new Difficulty(1.5, new MultiplyOperator(), 2));
diffsStack.add(new Difficulty(2, new AddOperator(), 10));

// simulate game loop
let time = 0;
setInterval(() => {
    // console.log('current time', time)

    if (time == '4') {
        diffsStack.add(new Difficulty(2, new ResetOperator(), 4));
    }
    if (time == '6') {
        diffsStack.add(new Difficulty(1, new ResetOperator(), 5));
    }
    diffsStack.addTime(1);
    const state = diffsStack.getCurrentState();
    console.log("time:", state.getTime());
    console.log('point: ', state.compute());
    time++;
}, 500);

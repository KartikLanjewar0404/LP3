pragma solidity >=0.7.0 <0.9.0;
// SPDX-License-Identifier: MIT

contract Bank {

    mapping(address => uint256) public balanceOf;   

    function deposit(uint256 amount) public payable {
        require(msg.value == amount,"Insufficient balance");
        balanceOf[msg.sender] += amount;     
    }

    function withdraw(uint256 amount) public {
        require(amount <= balanceOf[msg.sender],"insufficient balance");
        balanceOf[msg.sender] -= amount;
    }
    
    function showBalance() public view returns(uint256)
    {
        return balanceOf[msg.sender];
    }

}